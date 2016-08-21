#pragma once

#include "PopUp.h"

namespace cocos2d
{
	class DevelopPopUp
		: public PopUp
	{
	public:
		bool init(Node* parent);
		CREATE_POPUP(DevelopPopUp);

	};
}