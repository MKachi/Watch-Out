#include "OutPopUp.h"
#include "PopUpManager.h"
#include "UserRule.h"

using namespace cocos2d;

bool OutPopUp::init(Node* parent)
{
	if (!PopUp::init(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	parent->addChild(this);

	Sprite* background = Sprite::create("outPopUp.png");
	background->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(background);

	Button* yesButton = Button::create("YesButton.png", Color3B(125, 125, 125));
	yesButton->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
		Director::getInstance()->end();
	};
	yesButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 20);
	this->addChild(yesButton, true, 0);
	this->registeButton(yesButton);

	Button* closeButton = Button::create("pause/Cancel.png", Color3B(125, 125, 125));
	closeButton->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/cancelButton.mp3");
		PopUpManager::getInstance()->closePopUp();
	};
	closeButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 130);
	this->addChild(closeButton, true, 0);
	this->registeButton(closeButton);

	return true;
}