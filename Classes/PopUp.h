#pragma once

#include "cocos2d.h"
#include "Button.h"

namespace cocos2d
{
	struct PopUpInfo
	{
		Size popUpSize = Size(540.0f, 1120.0f);
		std::vector<Node*> _children;
		std::vector<int> _depth;
		std::vector<Button*> _touchObject;

		void addChild(Node* child, bool touchObject, int depth)
		{
			_children.push_back(child);
			_depth.push_back(depth);
			if (touchObject)
			{
				_touchObject.push_back((Button*)child);
			}
		}
		virtual void init() = 0;
	};

	class PopUp
		: public Sprite
	{
	private:
		cocos2d::LayerColor* _screen = nullptr;
		std::vector<Button*> _touchObject;

		bool init(PopUpInfo* info);

	protected:
		PopUp();
		virtual ~PopUp();

	public:
		static PopUp* create(const std::string& filename);
		static PopUp* create(PopUpInfo* info);

		void addBlackScreen();

		void show();
		void hide();

		void begin(Vec2 touchPoint);
		void ended(Vec2 touchPoint);

	};
}