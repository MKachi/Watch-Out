#pragma once

#include "cocos2d.h"

namespace cocos2d
{
	class Enemy
		: public Sprite
	{
	private:
		float	_speed;
		bool	_moveLeft;
		std::vector<std::string> _imageList;

		bool init(const std::initializer_list<std::string>& imageList);
		int randomIndex();

	protected:
		Enemy();
		virtual ~Enemy();

	public:
		static Enemy* create(const std::initializer_list<std::string>& imageList);
		void spawn();

		void update(float dt);

		void setMoveLeft(bool left);
		bool isMoveLeft() const { return _moveLeft; }

		void setSpeed(float speed);
		float getSpeed() { return _speed; }

	};
}