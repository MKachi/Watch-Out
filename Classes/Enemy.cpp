#include "Enemy.h"
#include "GameManager.h"
#include "UserRule.h"

using namespace cocos2d;

Enemy::Enemy()
{	}

Enemy::~Enemy()
{	}

Enemy* Enemy::create()
{
	Enemy* result = new (std::nothrow) Enemy();
	if (result != nullptr && result->initWithFile("Car1.png") && result->init())
	{
		result->autorelease();
		return result;
	}
	CC_SAFE_DELETE(result);

	return nullptr;
}

bool Enemy::init()
{
	auto sequence = Sequence::create({ MoveBy::create(0.1f, Vec2(0.0f, 3.0f)), MoveBy::create(0.1f, Vec2(0.0f, -3.0f)) });
	auto action = RepeatForever::create(sequence);
	this->runAction(action);

	return true;
}

int Enemy::randomIndex()
{
	std::random_device seed;
	std::mt19937 device(seed());
	std::uniform_int_distribution<int> dist(0, GameManager::getInstance()->getEnemyImageCount() - 1);
	return dist(device);
}

void Enemy::spawn()
{
	_originY = this->getPositionY();
	this->setVisible(true);
	this->setTexture(GameManager::getInstance()->getEnemyImage(randomIndex()));
}

void Enemy::update(float dt)
{
	if (!_visible)
	{
		return;
	}

	if (_moveLeft)
	{
		if (this->getPositionX() >= SCREEN_WIDTH / 2 + 475)
		{
			this->setVisible(false);
		}
		this->setPositionX(this->getPositionX() + _speed * dt);
	}
	else
	{
		if (this->getPositionX() <= SCREEN_WIDTH / 2 - 475)
		{
			this->setVisible(false);
		}
		this->setPositionX(this->getPositionX() - _speed * dt);
	}
}

void Enemy::setMoveLeft(bool left)
{
	_moveLeft = left;
	this->setFlippedX(left);
}

void Enemy::setSpeed(float speed)
{
	_speed = speed;
}