#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "TitleScene.h"
#include <sstream>
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

enum Depth
{
	PlatformArea,
	BackGround,
	Platform = 4,
	Friendly,
	Enemy,
	PauseButton,
	PausePopUp,
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

	GameManager::getInstance()->setScoreZero();
	GameManager::getInstance()->setDifficulty(Difficulty::Easy);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/Stage1.ogg");

	std::string backGroundNames[]=
	{
		"Background1.png", 
		"Background2.png", 
		"Background3.png", 
	};

	for (int i = 0; i < 3; ++i)
	{
		backGround[i] = Sprite::create(backGroundNames[i]);
		backGround[i]->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		this->addChild(backGround[i], 3 - i);
	}

	Rect area[] =
	{
		Rect(0, 0, 720, 475),
		Rect(0, 0, 720, 320),
		Rect(0, 0, 720, 320),
	};

	spawner = EnemySpawner::create(this);
	spawner->setDepth(Depth::Enemy);

	float y = SCREEN_HEIGHT / 2 + 220;
	for (int i = 0; i < 3; ++i)
	{
		GameManager::getInstance()->_playerCatche[i] = false;
		GameManager::getInstance()->_playerLife[i] = true;

		floor[i] = Floor::create("Temp_Platform.png", y + 105);
		floor[i]->setOpacity(0.0f);
		floor[i]->setPosition(SCREEN_WIDTH / 2, y);
		floor[i]->initArea(area[i], this);
		this->addChild(floor[i], Depth::Platform);

		friendly[i] = Friendly::create(GameManager::getInstance()->getSelectCountrys(i));
		friendly[i]->setPosition(SCREEN_WIDTH / 2, y + 105);
		friendly[i]->setBackPosition(friendly[i]->getPosition());
		friendly[i]->setOpacity(0.0f);
		friendly[i]->setFriendlyID(i);
		this->addChild(friendly[i], Depth::Friendly);

		spawnPoint[i].position = Vec2(SCREEN_WIDTH / 2 + 475, y + 105);
		spawnPoint[i].left = false;
		spawner->addSpawnPoint(spawnPoint[i]);

		spawnPoint[i + 1].position = Vec2(SCREEN_WIDTH / 2 - 475, y + 105);
		spawnPoint[i + 1].left = true;
		spawner->addSpawnPoint(spawnPoint[i + 1]);

		y -= 320.0f;
	}

	pauseButton = Button::create("Temp_Pause.png", Color3B(125, 125, 125));
	pauseButton->setPosition(SCREEN_WIDTH / 2 + 300, SCREEN_HEIGHT / 2 + 580);
	pauseButton->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
		Director::getInstance()->pause();
		menuButton->resume();
		cancelButton->resume();
		retryButton->resume();
		popUpLayer->setVisible(true);
	};
	this->addChild(pauseButton, Depth::PauseButton);

	GameManager::getInstance()->pushEnemyImage("Car1.png");
	GameManager::getInstance()->pushEnemyImage("Car2.png");
	GameManager::getInstance()->pushEnemyImage("Car3.png");

	GameManager::getInstance()->endGame = [=]()
	{
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		unschedule(schedule_selector(GameScene::update));
		unschedule(schedule_selector(GameScene::scoreUp));

		resultLayer->setPositionY(SCREEN_HEIGHT);
		setResultPopUp(true);
		schedule(schedule_selector(GameScene::delayTimer), 0.5f);
	};

	popUpLayer = LayerColor::create(Color4B(0, 0, 0, 191), SCREEN_WIDTH, SCREEN_HEIGHT);
	popUpLayer->setVisible(false);
	popUpLayer->setPosition(0, 0);
	this->addChild(popUpLayer, Depth::PausePopUp);

	popUpFrame = Sprite::create("pause/Frame.png");
	popUpFrame->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	popUpLayer->addChild(popUpFrame);

	menuButton = Button::create("pause/Menu.png", Color3B(125, 125, 125));
	menuButton->setPosition(popUpFrame->getContentSize().width / 2, popUpFrame->getContentSize().height / 2);
	menuButton->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
		Director::getInstance()->resume();
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(TransitionFade::create(2.0f, TitleScene::createScene(), Color3B::BLACK));
	};
	popUpFrame->addChild(menuButton);

	cancelButton = Button::create("pause/Cancel.png", Color3B(125, 125, 125));
	cancelButton->setPosition(popUpFrame->getContentSize().width / 2, popUpFrame->getContentSize().height / 2 - 200);
	cancelButton->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/cancelButton.ogg");
		Director::getInstance()->resume();
		popUpLayer->setVisible(false);
	};
	popUpFrame->addChild(cancelButton);

	retryButton = Button::create("pause/Retry.png", Color3B(125, 125, 125));
	retryButton->setPosition(popUpFrame->getContentSize().width / 2, popUpFrame->getContentSize().height / 2 + 200);
	retryButton->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
		Director::getInstance()->resume();
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(TransitionFade::create(2.0f, GameScene::createScene(), Color3B::BLACK));
	};
	popUpFrame->addChild(retryButton);

	resultLayer = LayerColor::create(Color4B(0, 0, 0, 191), SCREEN_WIDTH, SCREEN_HEIGHT * 2);
	resultLayer->setPosition(0.0f, 0.0f);
	resultLayer->setVisible(false);
	this->addChild(resultLayer, Depth::PausePopUp);

	resultFrame = Sprite::create("PopUpFrame.png");
	resultFrame->setPosition(Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	resultLayer->addChild(resultFrame);

	resultTitle = Sprite::create("result/result_title.png");
	resultTitle->setPosition(Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 450));
	resultLayer->addChild(resultTitle);

	Sprite* resultInfo = Sprite::create("result/resultInfo.png");
	resultInfo->setPosition(Vec2(SCREEN_WIDTH / 2 - 65, SCREEN_HEIGHT / 2 - 150));
	resultLayer->addChild(resultInfo);

	trophy = Sprite::create("result/Gold.png");
	trophy->setPosition(Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 200));
	resultLayer->addChild(trophy);

	bestScore = LabelTTF::create("", "font/verdana.ttf", 44.0f);
	bestScore->setPosition(Vec2(SCREEN_WIDTH / 2 + 40, SCREEN_HEIGHT / 2 - 65));
	bestScore->setAnchorPoint(Vec2(0.0f, 0.5f));
	resultLayer->addChild(bestScore);

	score = LabelTTF::create("", "font/verdana.ttf", 44.0f);
	score->setPosition(Vec2(SCREEN_WIDTH / 2 + 40, SCREEN_HEIGHT / 2 - 145));
	score->setAnchorPoint(Vec2(0.0f, 0.5f));
	resultLayer->addChild(score);

	obtain = LabelTTF::create("", "font/verdana.ttf", 44.0f);
	obtain->setPosition(Vec2(SCREEN_WIDTH / 2 + 40, SCREEN_HEIGHT / 2 - 235));
	obtain->setAnchorPoint(Vec2(0.0f, 0.5f));
	resultLayer->addChild(obtain);

	confirmButton = Button::create("result/ConfirmButton.png", Color3B(125, 125, 125));
	confirmButton->setPosition(Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 425));
	confirmButton->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
		// goto Title
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(TransitionFade::create(2.0f, TitleScene::createScene(), Color3B::BLACK));
	};
	resultLayer->addChild(confirmButton);

	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(GameScene::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(GameScene::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(GameScene::onTouchesEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	this->schedule(schedule_selector(GameScene::update));
	this->schedule(schedule_selector(GameScene::scoreUp), 1.0f);

	return true;
}

void GameScene::scoreUp(float dt)
{
	GameManager::getInstance()->upScore();
	CCLOG("Score : %d\n", GameManager::getInstance()->getScore());
}

void GameScene::delayTimer(float dt)
{
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/resultWindow.ogg");
	this->unschedule(schedule_selector(GameScene::delayTimer));
	auto action = EaseBackInOut::create(MoveTo::create(2.0f, Vec2(0.0f, 0.0f)));
	resultLayer->runAction(action);
}

std::string GameScene::intToString(int value)
{
	std::stringstream ss("");
	ss << value;
	return ss.str();
}

void GameScene::update(float dt)
{
	int score = GameManager::getInstance()->getScore();
	if (score >= 150)
	{
		GameManager::getInstance()->setDifficulty(Difficulty::Hard);
		if (backGround[(int)Difficulty::Normal]->getOpacity() >= 255.0f && backGround[(int)Difficulty::Normal]->isVisible())
		{
			if (backGround[(int)Difficulty::Normal]->getOpacity() <= 0.0f)
			{
				SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/Stage3.ogg");
				backGround[(int)Difficulty::Normal]->setVisible(false);
			}
			backGround[(int)Difficulty::Normal]->setOpacity(clampf(backGround[(int)Difficulty::Normal]->getOpacity() - 250.0f * dt, 0.0f, 255.0f));
		}
	}

	else if (score >= 50)
	{
		GameManager::getInstance()->setDifficulty(Difficulty::Normal);
		if (backGround[(int)Difficulty::Easy]->getOpacity() >= 0.0f && backGround[(int)Difficulty::Easy]->isVisible())
		{
			if (backGround[(int)Difficulty::Easy]->getOpacity() <= 0.0f)
			{
				SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/Stage2.ogg");
				backGround[(int)Difficulty::Easy]->setVisible(false);
			}
			backGround[(int)Difficulty::Easy]->setOpacity(clampf(backGround[(int)Difficulty::Easy]->getOpacity() - 250.0f * dt, 0.0f, 255.0f));
		}
	}

	spawner->update(dt);

	for (int i = 0; i < spawner->getEnemyCount(); ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (friendly[j]->isVisible())
			{
				if (friendly[j]->getBoundingBox().intersectsRect(spawner->getEnemy(i)->getBoundingBox()))
				{
					friendly[j]->die(spawner->getEnemy(i)->isMoveLeft());
				}
			}
		}
	}
}

void GameScene::setResultPopUp(bool active)
{
	int gameScore = GameManager::getInstance()->getScore();
	bestScore->setString(intToString(GameManager::getInstance()->getBestScore()));
	GameManager::getInstance()->addMoney(gameScore);

	score->setString(intToString(gameScore));
	obtain->setString(intToString(gameScore));

	if (gameScore >= 30)
	{
		trophy->setTexture("result/Gold.png");
	}
	else if (gameScore >= 20)
	{
		trophy->setTexture("result/Silver.png");
	}
	else if (gameScore >= 10)
	{
		trophy->setTexture("result/Bronze.png");
	}
	resultLayer->setVisible(active);
}

void GameScene::downResultPopUp(float dt)
{
	if (resultLayer->getPositionY() <= 0.0f)
	{
		resultLayer->setPositionY(0.0f);
		unschedule(schedule_selector(GameScene::downResultPopUp));
		return;
	}
	resultLayer->setPositionY(resultLayer->getPositionY() + 250 * dt);
}

void GameScene::onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	for (auto& touch : touches)
	{
		auto touchPoint = touch->getLocation();
		if (!popUpLayer->isVisible() && !resultLayer->isVisible())
		{
			pauseButton->begin(touchPoint);

			for (int i = 0; i < 3; ++i)
			{
				if (friendly[i]->isVisible())
				{
					if (friendly[i]->getBoundingBox().containsPoint(touchPoint))
					{
						friendly[i]->setMove(true);
						friendly[i]->setInLine(false);
						friendly[i]->setBackPosition(friendly[i]->getPosition());
						friendly[i]->setTouchID(touch->getID());
						friendly[i]->setPosition(touchPoint);
						return;
					}
				}
			}
		}
		else if (popUpLayer->isVisible())
		{
			Vec2 touchPoint = popUpLayer->convertToNodeSpace(popUpFrame->convertToNodeSpace(touch->getLocation()));
			menuButton->begin(touchPoint);
			cancelButton->begin(touchPoint);
			retryButton->begin(touchPoint);
		}
		else if (resultLayer->isVisible())
		{
			touchPoint = resultLayer->convertToNodeSpace(touch->getLocation());
			confirmButton->begin(touchPoint);
		}
	}
}

void GameScene::onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	if (!popUpLayer->isVisible())
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
}

void GameScene::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	for (auto& touch : touches)
	{
		auto touchPoint = touch->getLocation();

		if (!popUpLayer->isVisible() && !resultLayer->isVisible())
		{
			pauseButton->ended(touchPoint);

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
		else if (popUpLayer->isVisible())
		{
			Vec2 touchPoint = popUpLayer->convertToNodeSpace(popUpFrame->convertToNodeSpace(touch->getLocation()));
			menuButton->ended(touchPoint);
			cancelButton->ended(touchPoint);
			retryButton->ended(touchPoint);

			touchPoint = resultLayer->convertToNodeSpace(touch->getLocation());
			confirmButton->ended(touchPoint);
		}
		else if (resultLayer->isVisible())
		{
			touchPoint = resultLayer->convertToNodeSpace(touch->getLocation());
			confirmButton->ended(touchPoint);
		}
	}
}