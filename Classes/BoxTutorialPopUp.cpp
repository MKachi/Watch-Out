#include "BoxTutorialPopUp.h"
#include "PopUpManager.h"
#include "UserRule.h"

using namespace cocos2d;

bool BoxTutorialPopUp::init(Node* parent)
{
	if (!PopUp::init(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	parent->addChild(this);

	Sprite* background = Sprite::create("PopUpFrame.png");
	background->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(background);

	Sprite* text = Sprite::create("Question/RandomBoxText.png");
	text->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 100);
	this->addChild(text);

	Button* closeButton = Button::create("pause/Cancel.png", Color3B(125, 125, 125));
	closeButton->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/cancelButton.mp3");
		PopUpManager::getInstance()->closePopUp();
	};
	closeButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 430);
	this->addChild(closeButton, true, 0);
	this->registeButton(closeButton);

	return true;
}