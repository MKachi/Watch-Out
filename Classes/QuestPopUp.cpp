#include "QuestPopUp.h"
#include "PopUpManager.h"
#include "UserRule.h"
#include "TutorialPopUp.h"
#include "BoxTutorialPopUp.h"
#include "DevelopPopUp.h"

using namespace cocos2d;

bool QuestPopUp::init(Node* parent)
{
	if (!PopUp::init(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	parent->addChild(this);

	Sprite* background = Sprite::create("PopUpFrame.png");
	background->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(background);

	Button* tutorialButton = Button::create("Question/TutorialButton.png", Color3B(125, 125, 125));
	tutorialButton->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
		// show tutorial
		PopUpManager::getInstance()->openPopUp(TutorialPopUp::create(parent));
	};
	tutorialButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 370);
	this->addChild(tutorialButton, true, 0);
	this->registeButton(tutorialButton);

	Button* DevelopeButton = Button::create("Question/DeveloperButton.png", Color3B(125, 125, 125));
	DevelopeButton->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
		// DevelopeButton
		PopUpManager::getInstance()->openPopUp(DevelopPopUp::create(parent));
	};
	DevelopeButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 70);
	this->addChild(DevelopeButton, true, 0);
	this->registeButton(DevelopeButton);

	Button* RandomTutorial = Button::create("Question/RandomBoxButton.png", Color3B(125, 125, 125));
	RandomTutorial->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
		// RandomTutorial
		PopUpManager::getInstance()->openPopUp(BoxTutorialPopUp::create(parent));
	};
	RandomTutorial->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 230);
	this->addChild(RandomTutorial, true, 0); // Node, Button is true, zOther
	this->registeButton(RandomTutorial);

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