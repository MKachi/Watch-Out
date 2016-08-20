#pragma once

#include "cocos2d.h"

namespace cocos2d
{
	class Button
		: public Sprite
	{
	private:
		Color3B _originColor;
		Color3B _clickColor;
		bool _down = false;

		bool init(Color3B clickColor);

	protected:
		Button();
		virtual ~Button();

	public:
		static Button* create(const std::string& filename, Color3B color);

		void begin(Vec2 touchPoint);
		void ended(Vec2 touchPoint);
		std::function<void()> click = [=]() {};

	};
}