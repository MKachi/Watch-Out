#pragma once

#include "PopUp.h"

namespace cocos2d
{
	class QuestPopUp
		: public PopUp
	{
	public:
		bool init(Node* parent);
		CREATE_POPUP(QuestPopUp);

	};
}