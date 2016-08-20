#include "GameScene.h"
#include "GameManager.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

enum Depth
{
	PlatformArea,
	BackGround,
	Platform,
	Friendly,
	PauseButton,
};

Scene* GameScene::createScene()
{
    auto scene = Scene::create();

	auto layer = GameScene::create();
    scene->addChild(layer);

    return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	GameManager::getInstance()->setDifficulty(Difficulty::Hard);

	backGround = Sprite::create("Temp_Background.png");
	backGround->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(backGround, Depth::BackGround);

	Rect area[] =
	{
		Rect(0, 0, 720, 475),
		Rect(0, 0, 720, 320),
		Rect(0, 0, 720, 320),
	};

	spawner = EnemySpawner::create(this);
	float y = SCREEN_HEIGHT / 2 + 220;
	for (int i = 0; i < 3; ++i)
	{
		GameManager::getInstance()->setSelectCountrys(i, Country::Korea);

		floor[i] = Floor::create("Temp_Platform.png", y + 105);
		floor[i]->setPosition(SCREEN_WIDTH / 2, y);
		floor[i]->initArea(area[i], this);
		this->addChild(floor[i], Depth::Platform);

		friendly[i] = Friendly::create(GameManager::getInstance()->getSelectCountrys(i));
		friendly[i]->setPosition(SCREEN_WIDTH / 2, y + 105);
		friendly[i]->setBackPosition(friendly[i]->getPosition());
		this->addChild(friendly[i], Depth::Friendly);

		spawnPoint[i].position = Vec2(SCREEN_WIDTH / 2 + 475, y + 105);
		spawnPoint[i].left = false;
		spawner->addSpawnPoint(spawnPoint[i]);

		spawnPoint[i + 1].position = Vec2(SCREEN_WIDTH / 2 - 475, y + 105);
		spawnPoint[i + 1].left = true;
		spawner->addSpawnPoint(spawnPoint[i + 1]);

		y -= 320.0f;
	}

	pauseButton = Sprite::create("Temp_Pause.png");
	pauseOriginColor = pauseButton->getColor();
	pauseClickColor = Color3B(125, 125, 125);
	pauseButton->setPosition(SCREEN_WIDTH / 2 + 300, SCREEN_HEIGHT / 2 + 580);
	this->addChild(pauseButton, Depth::PauseButton);

	GameManager::getInstance()->pushEnemyImage("Temp_Car.png");

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(GameScene::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(GameScene::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(GameScene::onTouchesEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	this->schedule(schedule_selector(GameScene::update));

	return true;
}

void GameScene::update(float dt)
{
	spawner->update(dt);
}

void GameScene::showPausePopUp()
{

}

void GameScene::onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	for (auto& touch : touches)
	{
		auto touchPoint = touch->getLocation();
		if (pauseButton->getBoundingBox().containsPoint(touchPoint))
		{
			pauseTouchID = touch->getID();
			pauseButton->setColor(pauseClickColor);
			return;
		}

		for (int i = 0; i < 3; ++i)
		{
			if (friendly[i]->getBoundingBox().containsPoint(touchPoint))
			{
				friendly[i]->setMove(true);
				friendly[i]->setInLine(false);
				friendly[i]->setBackPosition(friendly[i]->getPosition());
				friendly[i]->setTouchID(touch->getID());
				return;
			}
		}
	}
}

void GameScene::onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	for (int i = 0; i < 3; ++i)
	{
		if (friendly[i]->isMove())
		{
			int touchID = friendly[i]->getTouchID();
			friendly[i]->setPosition(touches[touchID]->getLocation());
		}
	}
}

void GameScene::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	for (auto& touch : touches)
	{
		auto touchPoint = touch->getLocation();

		if (touch->getID() == pauseTouchID)
		{
			if (pauseButton->getBoundingBox().containsPoint(touchPoint))
			{
				showPausePopUp();
			}
			pauseButton->setColor(pauseOriginColor);
		}

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				floor[i]->dropCheck(friendly[j]);
			}
		}

		for (int i = 0; i < 3; ++i)
		{
			if (!friendly[i]->isInLine())
			{
				friendly[i]->setMove(false);
				friendly[i]->setPosition(friendly[i]->getBackPosition());
			}
		}
	}
}