#pragma once

#include "cocos2d.h"
#include "Button.h"
#include <forward_list>

#define CREATE_POPUP(_POPUP_) \
static _POPUP_* _POPUP_::create(Node* parent) \
{ \
	_POPUP_* result = new (std::nothrow) _POPUP_(); \
	if (result != nullptr && result->init(parent)) \
	{ \
		result->autorelease(); \
		return result; \
	} \
	CC_SAFE_DELETE(result); \
	return result; \
}

namespace cocos2d
{
	class PopUp
		: public LayerColor
	{
	private:
		std::forward_list<Button*> _buttons;

	public:
		virtual bool init(Color4B color);
		void registeButton(Button* button);

		void begin(Vec2 touchPoint);
		void ended(Vec2 touchPoint);

	};
}