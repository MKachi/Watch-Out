#include "QuestPopUp.h"
#include "PopUpManager.h"
#include "UserRule.h"
#include "TutorialPopUp.h"
#include "BoxTutorialPopUp.h"
#include "DevelopPopUp.h"

using namespace cocos2d;

bool TutorialPopUp::init(Node* parent)
{
	if (!PopUp::init(Color4B(0, 0, 0, 191)))
	{
		return false;
	}
	parent->addChild(this);

	_tutorialImages =
	{
		"tutorial/Tutorial_1.png",
		"tutorial/Tutorial_2.png",
		"tutorial/Tutorial_3.png",
		"tutorial/Tutorial_4.png",
		"tutorial/Tutorial_5.png",
		"tutorial/Tutorial_6.png" 
	};

	Sprite* background = Sprite::create("PopUpFrame.png");
	background->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(background);

	Sprite* tutorialImage = Sprite::create(_tutorialImages[index]);
	tutorialImage->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(tutorialImage);

	rightArrow = Button::create("teamSetting/Arrow.png", Color3B(125, 125, 125));
	rightArrow->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
		index += 1;
		if (index >= (int)_tutorialImages.size() - 1)
		{
			index = (int)_tutorialImages.size() - 1;
			rightArrow->setVisible(false);
		}
		leftArrow->setVisible(true);
		tutorialImage->setTexture(_tutorialImages[index]);
	};
	rightArrow->setPosition(SCREEN_WIDTH / 2 + 320, SCREEN_HEIGHT / 2 + 70);
	this->addChild(rightArrow);
	this->registeButton(rightArrow);

	leftArrow = Button::create("teamSetting/Arrow.png", Color3B(125, 125, 125));
	leftArrow->setVisible(false);
	leftArrow->setFlippedX(true);
	leftArrow->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
		index -= 1;
		if (index <= 0)
		{
			index = 0;
			leftArrow->setVisible(false);
		}
		rightArrow->setVisible(true);
		tutorialImage->setTexture(_tutorialImages[index]);
	};
	leftArrow->setPosition(SCREEN_WIDTH / 2 - 320, SCREEN_HEIGHT / 2 + 70);
	this->addChild(leftArrow);
	this->registeButton(leftArrow);

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