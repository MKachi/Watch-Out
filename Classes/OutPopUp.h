#pragma once

#include "PopUp.h"

namespace cocos2d
{
	class OutPopUp
		: public PopUp
	{
	public:
		bool init(Node* parent);
		CREATE_POPUP(OutPopUp);

	};
}