#include "TeamPopUp.h"
#include "PopUpManager.h"
#include "UserRule.h"
#include "GameManager.h"

using namespace cocos2d;

bool TeamPopUp::init(Node* parent)
{
	if (!PopUp::init(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	parent->addChild(this);

	Sprite* background = Sprite::create("PopUpFrame.png");
	background->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(background);

	_player1ImageName =
	{
		"teamSetting/1P_Korea.png",
		"teamSetting/1P_China.png",
		"teamSetting/1P_Japan.png",
		"teamSetting/1P_Peru.png",
		"teamSetting/1P_Philippines.png",
		"teamSetting/1P_Vietnam.png",
	};
	int index = (int)GameManager::getInstance()->getSelectCountrys(0);
	Sprite* player1Display = Sprite::create(_player1ImageName[index]);
	player1Display->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 370);
	this->addChild(player1Display);

	Sprite* p1 = Sprite::create("teamSetting/1P_Text.png");
	p1->setPosition(50, 220);
	player1Display->addChild(p1);

	Button* player1rightArrow = Button::create("teamSetting/Arrow.png", Color3B(125, 125, 125));
	player1rightArrow->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
		int index = (int)GameManager::getInstance()->getSelectCountrys(0);
		index += 1;

		if(index > (int)Country::Vietnam)
		{
			index = 0;
		}
		GameManager::getInstance()->setSelectCountrys(0, (Country)index);
		player1Display->setTexture(_player1ImageName[index]);
	};
	player1rightArrow->setPosition(SCREEN_WIDTH / 2 + 220, SCREEN_HEIGHT / 2 + 370);
	this->addChild(player1rightArrow);
	this->registeButton(player1rightArrow);

	Button* player1leftArrow = Button::create("teamSetting/Arrow.png", Color3B(125, 125, 125));
	player1leftArrow->setFlippedX(true);
	player1leftArrow->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
		int index = (int)GameManager::getInstance()->getSelectCountrys(0);
		index -= 1;
		if (index < 0)
		{
			index = (int)Country::Vietnam;
		}
		GameManager::getInstance()->setSelectCountrys(0, (Country)index);
		player1Display->setTexture(_player1ImageName[index]);
	};
	player1leftArrow->setPosition(SCREEN_WIDTH / 2 - 220, SCREEN_HEIGHT / 2 + 370);
	this->addChild(player1leftArrow);
	this->registeButton(player1leftArrow);

	_player2ImageName =
	{
		"teamSetting/2P_Korea.png",
		"teamSetting/2P_China.png",
		"teamSetting/2P_Japan.png",
		"teamSetting/2P_Peru.png",
		"teamSetting/2P_Philippines.png",
		"teamSetting/2P_Vietnam.png",
	};
	index = (int)GameManager::getInstance()->getSelectCountrys(1);
	Sprite* player2Display = Sprite::create(_player2ImageName[index]);
	player2Display->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 70);
	this->addChild(player2Display);

	Sprite* p2 = Sprite::create("teamSetting/2P_Text.png");
	p2->setPosition(50, 220);
	player2Display->addChild(p2);

	Button* player2rightArrow = Button::create("teamSetting/Arrow.png", Color3B(125, 125, 125));
	player2rightArrow->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
		int index = (int)GameManager::getInstance()->getSelectCountrys(1);
		index += 1;

		if (index > (int)Country::Philippines)
		{
			index = 0;
		}
		GameManager::getInstance()->setSelectCountrys(1, (Country)index);
		player2Display->setTexture(_player2ImageName[index]);
	};
	player2rightArrow->setPosition(SCREEN_WIDTH / 2 + 220, SCREEN_HEIGHT / 2 + 70);
	this->addChild(player2rightArrow);
	this->registeButton(player2rightArrow);

	Button* player2leftArrow = Button::create("teamSetting/Arrow.png", Color3B(125, 125, 125));
	player2leftArrow->setFlippedX(true);
	player2leftArrow->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
		int index = (int)GameManager::getInstance()->getSelectCountrys(1);
		index -= 1;
		if (index < 0)
		{
			index = (int)Country::Philippines;
		}
		GameManager::getInstance()->setSelectCountrys(1, (Country)index);
		player2Display->setTexture(_player2ImageName[index]);
	};
	player2leftArrow->setPosition(SCREEN_WIDTH / 2 - 220, SCREEN_HEIGHT / 2 + 70);
	this->addChild(player2leftArrow);
	this->registeButton(player2leftArrow);

	_player3ImageName =
	{
		"teamSetting/3P_Korea.png",
		"teamSetting/3P_China.png",
		"teamSetting/3P_Japan.png",
		"teamSetting/3P_Peru.png",
		"teamSetting/3P_Philippines.png",
		"teamSetting/3P_Vietnam.png",
	};
	index = (int)GameManager::getInstance()->getSelectCountrys(2);
	Sprite* player3Display = Sprite::create(_player3ImageName[index]);
	player3Display->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 230);
	this->addChild(player3Display);

	Sprite* p3 = Sprite::create("teamSetting/3P_Text.png");
	p3->setPosition(50, 220);
	player3Display->addChild(p3);

	Button* player3rightArrow = Button::create("teamSetting/Arrow.png", Color3B(125, 125, 125));
	player3rightArrow->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
		int index = (int)GameManager::getInstance()->getSelectCountrys(2);
		index += 1;

		if (index > (int)Country::Philippines)
		{
			index = 0;
		}
		GameManager::getInstance()->setSelectCountrys(2, (Country)index);
		player3Display->setTexture(_player3ImageName[index]);
	};
	player3rightArrow->setPosition(SCREEN_WIDTH / 2 + 220, SCREEN_HEIGHT / 2 - 230);
	this->addChild(player3rightArrow);
	this->registeButton(player3rightArrow);

	Button* player3leftArrow = Button::create("teamSetting/Arrow.png", Color3B(125, 125, 125));
	player3leftArrow->setFlippedX(true);
	player3leftArrow->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
		int index = (int)GameManager::getInstance()->getSelectCountrys(2);
		index -= 1;
		if (index < 0)
		{
			index = (int)Country::Philippines;
		}
		GameManager::getInstance()->setSelectCountrys(2, (Country)index);
		player3Display->setTexture(_player3ImageName[index]);
	};
	player3leftArrow->setPosition(SCREEN_WIDTH / 2 - 220, SCREEN_HEIGHT / 2 - 230);
	this->addChild(player3leftArrow);
	this->registeButton(player3leftArrow);

	Button* closeButton = Button::create("result/ConfirmButton.png", Color3B(125, 125, 125));
	closeButton->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
		PopUpManager::getInstance()->closePopUp();
	};
	closeButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 430);
	this->addChild(closeButton);
	this->registeButton(closeButton);

	return true;
}