#pragma once

#include "cocos2d.h"
#include "Enemy.h"

namespace cocos2d
{
	struct SpawnPoint
	{
		Vec2 position;
		bool left;
	};

	class EnemySpawner
	{
		enum { POOL_SIZE = 10, };
	private:
		Enemy*		_enemys[POOL_SIZE];
		float		_spawnDelay;
		float		_spawnDelayCount;
		std::vector<SpawnPoint> _spawnPoints;

		bool init(Node* layer);
		float random_float(float min, float max);
		int random_int(int min, int max);
		float delayRandom();

	protected:
		EnemySpawner();
		virtual ~EnemySpawner();

	public:
		static EnemySpawner* create(Node* layer);
		void update(float dt);

		void addSpawnPoint(SpawnPoint spawnPoint);
		Enemy* getEnemy(int index) { return _enemys[index]; }

	};
}