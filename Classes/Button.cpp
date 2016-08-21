#include "Button.h"

using namespace cocos2d;

Button::Button()
{	}

Button::~Button()
{	}

Button* cocos2d::Button::create(const std::string& filename, Color3B color)
{
	Button* result = new (std::nothrow) Button();
	if (result != nullptr && result->init(color) && result->initWithFile(filename))
	{
		return result;
	}
	CC_SAFE_DELETE(result);

	return nullptr;
}

bool Button::init(Color3B clickColor)
{
	_originColor = this->getColor();
	_clickColor = clickColor;
	return true;
}

void Button::begin(Vec2 touchPoint)
{
	if (this->getBoundingBox().containsPoint(touchPoint))
	{
		_down = true;
		this->setColor(_clickColor);
	}
}

void Button::ended(Vec2 touchPoint)
{
	if (this->getBoundingBox().containsPoint(touchPoint))
	{
		if (_down)
		{
			_down = false;
			click();
		}
	}
	this->setColor(_originColor);
}