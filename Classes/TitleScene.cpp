#include "TitleScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* TitleScene::createScene()
{
	auto scene = Scene::create();

	auto layer = TitleScene::create();
	scene->addChild(layer);

	return scene;
}

bool TitleScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	backGround = Sprite::create("title/title_background.png");
	backGround->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(backGround);

	Sprite* charSprite = Sprite::create("title/Temp_Char.png");
	charSprite->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(charSprite);

	auto upAction = EaseOut::create(MoveBy::create(1.0f, Vec2(0.0f, 20.0f)), 1.0f);
	auto downAction = EaseOut::create(MoveBy::create(1.0f, Vec2(0.0f, -20.0f)), 1.0f);
	auto action = RepeatForever::create(Sequence::create(upAction, downAction, NULL));

	titleText = Sprite::create("title/titleText.png");
	titleText->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 400);
	this->addChild(titleText);
	titleText->runAction(action);

	mainPopUpButton = Button::create("title/mainPopUpButton.png", Color3B(125, 125, 125));
	mainPopUpButton->click = [=]()
	{
		mainPopUp->show(); // showPopUp
	};
	mainPopUpButton->setPosition(SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT / 2 - 410);
	this->addChild(mainPopUpButton);

	helpPopUpButton = Button::create("title/helpButton.png", Color3B(125, 125, 125));
	helpPopUpButton->setPosition(SCREEN_WIDTH / 2 + 250, SCREEN_HEIGHT / 2 - 410);
	this->addChild(helpPopUpButton);

	startButton = Button::create("title/playButton.png", Color3B(125, 125, 125));
	startButton->click = [=]()
	{
		Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
		Director::getInstance()->replaceScene(TransitionFade::create(2.0f, GameScene::createScene(), Color3B::BLACK));
	};
	startButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 320);
	this->addChild(startButton);

	// PopUp Sample
	struct MainPopUp
		: public PopUpInfo
	{
		void init() override
		{
			Button* teamSetting = Button::create("mainPopUp/TeamSetting.png", Color3B(125, 125, 125));
			teamSetting->click = [=]()
			{
				// Show TeamSetting
			};
			teamSetting->setPosition(popUpSize.width / 2, popUpSize.height / 2 + 370);
			this->addChild(teamSetting, true, 0);

			Button* collection = Button::create("mainPopUp/Collection.png", Color3B(125, 125, 125));
			collection->click = [=]()
			{
				// Show Collection
				CCLOG("Test\n");
			};
			collection->setPosition(popUpSize.width / 2, popUpSize.height / 2 + 70);
			this->addChild(collection, true, 0);

			Button* randomBox = Button::create("mainPopUp/RandomBox.png", Color3B(125, 125, 125));
			randomBox->click = [=]()
			{
				// Show RandomBox
			};
			randomBox->setPosition(popUpSize.width / 2, popUpSize.height / 2 - 230);
			this->addChild(randomBox, true, 0); // Node, Button is true, zOther

			Button* closeButton = Button::create("pause/Cancel.png", Color3B(125, 125, 125));
			closeButton->click = [=]()
			{
				// ClosePopUp
				((PopUp*)closeButton->getParent())->hide(); // Hide PopUp
			};
			closeButton->setPosition(popUpSize.width / 2, popUpSize.height / 2 - 430);
			this->addChild(closeButton, true, 0);
		}
	};
	mainPopUp = PopUp::create(new MainPopUp());
	mainPopUp->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(mainPopUp);
	popUps.push_back(mainPopUp); // add PopUp List
	
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(TitleScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(TitleScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	this->schedule(schedule_selector(TitleScene::update));

	return true;
}

void TitleScene::update(float dt)
{
	bool showPopUp = false;
	for (int i = 0; i < popUps.size(); ++i)
	{
		if (popUps[i]->isVisible())
		{
			showPopUp = true;
		}
	}
	mainPopUpButton->setVisible(!showPopUp);
	helpPopUpButton->setVisible(!showPopUp);
	startButton->setVisible(!showPopUp);
}

bool TitleScene::onTouchBegan(Touch* touch, Event* event)
{
	Vec2 touchPoint = touch->getLocation();
	mainPopUpButton->begin(touchPoint);
	helpPopUpButton->begin(touchPoint);
	startButton->begin(touchPoint);
	mainPopUp->begin(touchPoint); // Send Touch
	return true;
}

void TitleScene::onTouchMoved(Touch* touch, Event* event)
{
}

void TitleScene::onTouchEnded(Touch* touch, Event* event)
{
	Vec2 touchPoint = touch->getLocation();
	mainPopUpButton->ended(touchPoint);
	helpPopUpButton->ended(touchPoint);
	startButton->ended(touchPoint);
	mainPopUp->ended(touchPoint); // Send Touch
}