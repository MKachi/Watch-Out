#pragma once

#include "cocos2d.h"

namespace cocos2d
{
	class Enemy
		: public Sprite
	{
	private:
		float	_speed = 300.0f;
		float	_originY = 0.0f;
		bool	_moveLeft;

		bool init();
		int randomIndex();

	protected:
		Enemy();
		virtual ~Enemy();

	public:
		static Enemy* create();
		void spawn();

		void update(float dt);

		void setMoveLeft(bool left);
		bool isMoveLeft() const { return _moveLeft; }

		void setSpeed(float speed);
		float getSpeed() { return _speed; }

	};
}