#include "BoxResultPopUp.h"
#include "PopUpManager.h"
#include "UserRule.h"
#include "GameManager.h"

using namespace cocos2d;

bool BoxResultPopUp::init(Node* parent)
{
	if (!PopUp::init(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	parent->addChild(this);

	_itemSet = new ItemSet();
	std::string itemName = _itemSet->getVector()[RandomIndex()]->name;

	if (UserDefault::getInstance()->getBoolForKey(itemName.c_str()))
	{
		while (true)
		{
			itemName = _itemSet->getVector()[RandomIndex()]->name;
			if (!UserDefault::getInstance()->getBoolForKey(itemName.c_str()))
			{
				UserDefault::getInstance()->setBoolForKey(itemName.c_str(), true); // true : unlocked, false : lock
				break;
			}
		}
	}

	int count = UserDefault::getInstance()->getIntegerForKey("ItemCount");
	UserDefault::getInstance()->setIntegerForKey("ItemCount", count + 1);

	Sprite* background = Sprite::create("PopUpFrame.png");
	background->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(background);

	Sprite* title = Sprite::create("random/resultTitle.png");
	title->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 470);
	this->addChild(title);

	Sprite* image = Sprite::create("random/sample.png");
	image->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 90);
	this->addChild(image);

	Sprite* name = Sprite::create("random/sample2.png");
	name->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 300);
	this->addChild(name);

	Button* cancelButton = Button::create("result/ConfirmButton.png", Color3B(125, 125, 125));
	cancelButton->click = [=]()
	{
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
		PopUpManager::getInstance()->closePopUp();
	};
	cancelButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 430);
	this->addChild(cancelButton);
	this->registeButton(cancelButton);

	return true;
}

int BoxResultPopUp::RandomIndex()
{
	std::random_device seed;
	std::mt19937 device(seed());
	std::uniform_int_distribution<int> dist(0, _itemSet->getVector().size() - 1);
	return dist(device);
	return 0;
}
