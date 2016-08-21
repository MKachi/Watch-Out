#include "EnenySpawner.h"
#include "GameManager.h"

using namespace cocos2d;

EnemySpawner::EnemySpawner()
{	}

EnemySpawner::~EnemySpawner()
{	}

EnemySpawner* EnemySpawner::create(Node* layer)
{
	EnemySpawner* result = new (std::nothrow) EnemySpawner();
	if (result != nullptr && result->init(layer))
	{
		return result;
	}
	CC_SAFE_DELETE(result);

	return nullptr;
}

bool EnemySpawner::init(Node* layer)
{
	for (int i = 0; i < POOL_SIZE; ++i)
	{
		_enemys[i] = Enemy::create();
		_enemys[i]->setVisible(false);
		layer->addChild(_enemys[i], 99);
	}

	_spawnDelay = delayRandom();
	_spawnDelayCount = 0.0f;

	return true;
}

float EnemySpawner::random_float(float min, float max)
{
	std::random_device seed;
	std::mt19937 device(seed());
	std::uniform_real_distribution<float> dist(min, max);
	return dist(device);
}

int EnemySpawner::random_int(int min, int max)
{
	std::random_device seed;
	std::mt19937 device(seed());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(device);
}

float EnemySpawner::delayRandom()
{
	switch (GameManager::getInstance()->getDifficulty())
	{
	case Difficulty::Easy:
		return random_float(4.0f, 6.0f);

	case Difficulty::Normal:
		return random_float(3.0f, 5.0f);

	case Difficulty::Hard:
		return random_float(1.0f, 2.0f);
	}
}

void EnemySpawner::update(float dt)
{
	_spawnDelayCount += dt;
	if (_spawnDelay <= _spawnDelayCount)
	{
		_spawnDelay = delayRandom();
		_spawnDelayCount = 0.0f;

		for (int j = 0; j < POOL_SIZE; ++j)
		{
			if (!_enemys[j]->isVisible())
			{
				int index = random_int(0, 5);
				_enemys[j]->spawn();
				_enemys[j]->setPosition(_spawnPoints[index].position);
				_enemys[j]->setMoveLeft(_spawnPoints[index].left);
				break;
			}
		}
	}

	for (int i = 0; i < POOL_SIZE;++i)
	{
		_enemys[i]->update(dt);
	}
}

void EnemySpawner::addSpawnPoint(SpawnPoint spawnPoint)
{
	_spawnPoints.push_back(spawnPoint);
}

void EnemySpawner::setDepth(int depth)
{
	for (int i = 0; i < POOL_SIZE;++i)
	{
		_enemys[i]->setZOrder(depth);
	}
}
