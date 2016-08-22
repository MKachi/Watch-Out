#include "RandomBoxPopUp.h"
#include "PopUpManager.h"
#include "UserRule.h"
#include "GameManager.h"
#include "BoxResultPopUp.h"

using namespace cocos2d;

bool RandomBoxPopUp::init(Node* parent)
{
	if (!PopUp::init(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	parent->addChild(this);

	Sprite* background = Sprite::create("PopUpFrame.png");
	background->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(background);

	Sprite* big = Sprite::create("random/BigBox.png");
	big->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 330);
	this->addChild(big);

	Sprite* text = Sprite::create("random/BoxFonts.png");
	text->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50);
	this->addChild(text);

	std::stringstream ss;
	ss << GameManager::getInstance()->getMoney();

	_money = LabelTTF::create(ss.str(), "fonts/verdana.ttf", 44.0f);
	_money->setPosition(Vec2(SCREEN_WIDTH / 2 + 20, SCREEN_HEIGHT / 2 + 150));
	_money->setAnchorPoint(Vec2(1.0f, 0.5f));
	this->addChild(_money);

	Sprite* icon = Sprite::create("random/moneyIcon.png");
	icon->setPosition(SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT / 2 + 150);
	this->addChild(icon);

	ItemSet* itemSet = new ItemSet();

	Button* buyButton = Button::create("random/BuyButton.png", Color3B(125, 125, 125));
	buyButton->click = [=]()
	{
		int count = UserDefault::getInstance()->getIntegerForKey("ItemCount");
		int money = GameManager::getInstance()->getMoney();
		if (money < 100 || count >= itemSet->getVector().size())
		{
			SimpleAudioEngine::getInstance()->playEffect("sound/Error.mp3");
			return;
		}
		SimpleAudioEngine::getInstance()->playEffect("sound/boxOpen.mp3");
		GameManager::getInstance()->minusMoney(100);

		std::stringstream ss;
		ss << GameManager::getInstance()->getMoney();
		_money->setString(ss.str());

		PopUpManager::getInstance()->openPopUp(BoxResultPopUp::create(parent));
	};
	buyButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 200);
	this->addChild(buyButton);
	this->registeButton(buyButton);

	int count = UserDefault::getInstance()->getIntegerForKey("ItemCount");
	if (count >= itemSet->getVector().size())
	{
		buyButton->setColor(Color3B(125, 125, 125));
	}

	Button* cancelButton = Button::create("pause/Cancel.png", Color3B(125, 125, 125));
	cancelButton->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/cancelButton.mp3");
		PopUpManager::getInstance()->closePopUp();
	};
	cancelButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 430);
	this->addChild(cancelButton);
	this->registeButton(cancelButton);

	return true;
}