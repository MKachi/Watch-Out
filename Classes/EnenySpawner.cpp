#include "EnenySpawner.h"
#include "GameManager.h"

using namespace cocos2d;

EnemySpawner::EnemySpawner()
{	}

EnemySpawner::~EnemySpawner()
{	}

EnemySpawner* EnemySpawner::create(const size_t poolSize, const std::initializer_list<std::string>& imageList, const std::initializer_list<SpawnPoint>& spawnPoints, Node* layer)
{
	EnemySpawner* result = new (std::nothrow) EnemySpawner();
	if (result != nullptr && result->init(poolSize, imageList, spawnPoints, layer))
	{
		result->autorelease();
		return result;
	}
	return nullptr;
}

bool EnemySpawner::init(const size_t poolSize, const std::initializer_list<std::string>& imageList, const std::initializer_list<SpawnPoint>& spawnPoints, Node* layer)
{
	for (int i = 0; i < _poolSize; ++i)
	{
		Enemy* temp = Enemy::create(imageList);
		layer->addChild(temp);

		_enemys.emplace_back(temp);
	}

	for (auto& point : spawnPoints)
	{
		_spawnPoints.push_back(point);
	}

	return true;
}

float EnemySpawner::random_float(float min, float max)
{
	std::random_device seed;
	std::mt19937 device(seed());
	std::uniform_real_distribution<float> dist(min, max);
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
	for (int i = 0; i < 6;++i)
	{
		_spawnDelayCount[i] += dt;
		if (_spawnDelay[i] <= _spawnDelayCount[i])
		{
			Enemy* enemy = getUseableEnemy();
			enemy->spawn();
			enemy->setPosition(_spawnPoints[i].position);
			enemy->setMoveLeft(_spawnPoints[i].left);

			_spawnDelay[i] = delayRandom();
			_spawnDelayCount[i] = 0;
		}
	}
}

Enemy* EnemySpawner::getUseableEnemy()
{
	for (int i = 0; i < _enemys.size(); ++i)
	{
		if (!_enemys[i]->isVisible())
		{
			return _enemys[i];
		}
	}
}