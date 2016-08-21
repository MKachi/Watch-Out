#pragma once

#include "PopUp.h"
#include <vector>

namespace cocos2d
{
	class RandomBoxPopUp
		: public PopUp
	{
	public:
		bool init(Node* parent);
		CREATE_POPUP(RandomBoxPopUp);

		LabelTTF* _money;

	};
}