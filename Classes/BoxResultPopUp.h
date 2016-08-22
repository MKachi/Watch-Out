#pragma once

#include "PopUp.h"
#include "ItemSet.h"
#include <vector>

namespace cocos2d
{
	class BoxResultPopUp
		: public PopUp
	{
	public:
		bool init(Node* parent);
		CREATE_POPUP(BoxResultPopUp);

		ItemSet* _itemSet;

		int RandomIndex(int size);

	};
}