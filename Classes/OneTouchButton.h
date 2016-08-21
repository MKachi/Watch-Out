#pragma once

#include "cocos2d.h"

namespace cocos2d
{
	class OneTouchButton
		: public Sprite
	{
	private:
		Color3B _originColor;
		Color3B _clickColor;

		virtual void onEnter();
		virtual void onExit();

		bool init(Color3B clickColor);

	protected:
		OneTouchButton();
		virtual ~OneTouchButton();

	public:
		static OneTouchButton* create(const std::string& filename, Color3B color);

		std::function<void()> click = [=]() {};

	};
}