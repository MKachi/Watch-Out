#pragma once

#include "PopUp.h"
#include <vector>

namespace cocos2d
{
	class TeamPopUp
		: public PopUp
	{
	public:
		bool init(Node* parent);
		CREATE_POPUP(TeamPopUp);

		std::vector<std::string> _player1ImageName;
		std::vector<std::string> _player2ImageName;
		std::vector<std::string> _player3ImageName;

	};
}