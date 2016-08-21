#pragma once

#include "PopUp.h"
#include <vector>

namespace cocos2d
{
	class TutorialPopUp
		: public PopUp
	{
	public:
		bool init(Node* parent);
		CREATE_POPUP(TutorialPopUp);

		int index = 0;
		std::vector<std::string> _tutorialImages;
		Button* leftArrow;
		Button* rightArrow;

	};
}