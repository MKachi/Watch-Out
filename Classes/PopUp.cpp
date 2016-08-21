#include "PopUp.h"
#include "UserRule.h"

using namespace cocos2d;

bool PopUp::init(Color4B color)
{
	if (!LayerColor::initWithColor(color))
	{
		return false;
	}
	return true;
}

void PopUp::registeButton(Button* button)
{
	_buttons.push_front(button);
}

void PopUp::begin(Vec2 touchPoint)
{
	if (!this->isVisible())
	{
		return;
	}
	Vec2 location = this->convertToNodeSpace(touchPoint);

	for (auto iter = _buttons.cbegin(); iter != _buttons.cend(); ++iter)
	{
		(*iter)->begin(touchPoint);
	}
}

void PopUp::ended(Vec2 touchPoint)
{
	if (!this->isVisible())
	{
		return;
	}
	Vec2 location = this->convertToNodeSpace(touchPoint);

	for (auto iter = _buttons.cbegin(); iter != _buttons.cend(); ++iter)
	{
		(*iter)->ended(touchPoint);
	}
}