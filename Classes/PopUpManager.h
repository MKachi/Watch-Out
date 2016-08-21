#pragma once

#include "cocos2d.h"
#include "PopUp.h"
#include <stack>

namespace cocos2d
{
	class PopUpManager
	{
	private:
		std::stack<PopUp*> _stack;

	public:
		static PopUpManager* getInstance();
		static void destroy();

		void openPopUp(PopUp* popUp);
		void closePopUp();

		PopUp* getCurrentShowPopUp();
		bool isShowPopUp() { return !_stack.empty(); }

	};
}