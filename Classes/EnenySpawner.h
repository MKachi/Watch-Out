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
		: public Node
	{
	private:
		std::vector<Enemy*>		_enemys;
		std::vector<SpawnPoint>		_spawnPoints;
		size_t		_poolSize;
		float		_spawnDelay[6];
		float		_spawnDelayCount[6];

		bool init(const size_t poolSize, const std::initializer_list<std::string>& imageList, const std::initializer_list<SpawnPoint>& spawnPoints, Node* layer);
		float delayRandom();
		Enemy* getUseableEnemy();

	protected:
		EnemySpawner();
		virtual ~EnemySpawner();

	public:
		static EnemySpawner* create(const size_t poolSize, const std::initializer_list<std::string>& imageList, const std::initializer_list<SpawnPoint>& spawnPoints, Node* layer);
		void update(float dt);

	};
}