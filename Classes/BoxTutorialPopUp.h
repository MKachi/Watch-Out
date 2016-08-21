#pragma once

#include "PopUp.h"

namespace cocos2d
{
	class BoxTutorialPopUp
		: public PopUp
	{
	public:
		bool init(Node* parent);
		CREATE_POPUP(BoxTutorialPopUp);

	};
}