#pragma once

#include "cocos2d.h"
#include "Friendly.h"

namespace cocos2d
{
	class GameManager
	{
	private:
		Country _country[3];

	public:
		static GameManager* getInstance();
		static void destroy();

		void setSelectCountrys(const int index, Country country);
		Country getSelectCountrys(const int index) { return _country[index]; }

	};
}