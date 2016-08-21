#include "TitleScene.h"
#include "GameScene.h"
#include "MainPopUp.h"
#include "PopUpManager.h"

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
		PopUpManager::getInstance()->openPopUp(MainPopUp::create(this)); // OpenPopUp
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
	bool showPopUp = PopUpManager::getInstance()->isShowPopUp();
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

	PopUp* currentPopUp = PopUpManager::getInstance()->getCurrentShowPopUp();
	if (currentPopUp != nullptr)
	{
		currentPopUp->begin(touchPoint);
	}

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
	PopUp* currentPopUp = PopUpManager::getInstance()->getCurrentShowPopUp();
	if (currentPopUp != nullptr)
	{
		currentPopUp->ended(touchPoint);
	}
}