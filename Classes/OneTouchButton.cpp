#include "OneTouchButton.h"

using namespace cocos2d;

OneTouchButton::OneTouchButton()
{	}

OneTouchButton::~OneTouchButton()
{	}

OneTouchButton* OneTouchButton::create(const std::string& filename, Color3B color)
{
	OneTouchButton* result = new (std::nothrow) OneTouchButton();
	if (result != nullptr && result->init(color) && result->initWithFile(filename))
	{
		result->autorelease();
		return result;
	}
	CC_SAFE_DELETE(result);

	return nullptr;
}

bool OneTouchButton::init(Color3B clickColor)
{
	_clickColor = clickColor;
	_originColor = this->getColor();
	return true;
}

void OneTouchButton::onEnter()
{
	Sprite::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [=](cocos2d::Touch* touch, cocos2d::Event* _event)
	{
		auto touchPoint = this->convertToNodeSpace(touch->getLocation());
		Size s = this->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		if (rect.containsPoint(touchPoint))
		{
			this->setColor(_clickColor);
			return true;
		}
		return true;
	};

	listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* _event)
	{
		auto touchPoint = this->convertToNodeSpace(touch->getLocation());
		Size s = this->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		if (rect.containsPoint(touchPoint))
		{
			click();
		}
		this->setColor(_originColor);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void OneTouchButton::onExit()
{
	_eventDispatcher->removeEventListenersForTarget(this);
	Sprite::onExit();
}