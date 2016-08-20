#pragma once

#include "cocos2d.h"

namespace cocos2d
{
	class EnemySpawner
		: public Node
	{
	private:
		Sprite** _enemy;
		size_t _poolSize;
		float _spawnDelay[6];
		Vec2 _spawnPoints[6];

	protected:
		EnemySpawner();
		virtual ~EnemySpawner();

	public:
		static EnemySpawner* create(const size_t poolSize, const std::vector<std::string>& imageList);
		void update(float dt);

	};
}