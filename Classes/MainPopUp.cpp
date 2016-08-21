#include "MainPopUp.h"
#include "PopUpManager.h"
#include "UserRule.h"
#include "TeamPopUp.h"

using namespace cocos2d;

bool MainPopUp::init(Node* parent)
{
	if (!PopUp::init(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	parent->addChild(this);

	Sprite* background = Sprite::create("PopUpFrame.png");
	background->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(background);

	Button* teamSetting = Button::create("mainPopUp/TeamSetting.png", Color3B(125, 125, 125));
	teamSetting->click = [=]()
	{
		// Show TeamSetting
		PopUpManager::getInstance()->openPopUp(TeamPopUp::create(parent));
	};
	teamSetting->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 370);
	this->addChild(teamSetting, true, 0);
	this->registeButton(teamSetting);

	Button* collection = Button::create("mainPopUp/Collection.png", Color3B(125, 125, 125));
	collection->click = [=]()
	{
		// Show Collection
		CCLOG("Test\n");
	};
	collection->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 70);
	this->addChild(collection, true, 0);
	this->registeButton(collection);

	Button* randomBox = Button::create("mainPopUp/RandomBox.png", Color3B(125, 125, 125));
	randomBox->click = [=]()
	{
		// Show RandomBox
	};
	randomBox->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 230);
	this->addChild(randomBox, true, 0); // Node, Button is true, zOther
	this->registeButton(randomBox);

	Button* closeButton = Button::create("pause/Cancel.png", Color3B(125, 125, 125));
	closeButton->click = [=]()
	{
		PopUpManager::getInstance()->closePopUp();
	};
	closeButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 430);
	this->addChild(closeButton, true, 0);
	this->registeButton(closeButton);

	return true;
}