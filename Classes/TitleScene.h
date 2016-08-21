#pragma once

#include "cocos2d.h"

namespace cocos2d
{
	class TitleScene
		: public Layer
	{
	public:
		static cocos2d::Scene* createScene();

		virtual bool init();

		CREATE_FUNC(TitleScene);

	private:


	};
}