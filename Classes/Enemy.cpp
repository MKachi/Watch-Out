#include "Enemy.h"

using namespace cocos2d;

Enemy::Enemy()
{	}

Enemy::~Enemy()
{	}

Enemy* Enemy::create(const std::initializer_list<std::string>& imageList)
{
	Enemy* result = new (std::nothrow) Enemy();
	if (result != nullptr && result->init(imageList))
	{
		result->autorelease();
		return result;
	}
	return nullptr;
}

bool Enemy::init(const std::initializer_list<std::string>& imageList)
{
	for (auto& iter : imageList)
	{
		_imageList.emplace_back(iter);
	}
	this->setVisible(false);

	return true;
}

int Enemy::randomIndex()
{
	std::random_device seed;
	std::mt19937 device(seed());
	std::uniform_int_distribution<> dist(0, _imageList.size());
	return dist(device);
}

void Enemy::spawn()
{
	this->setTexture(_imageList[randomIndex()]);
	this->setVisible(true);
}

void Enemy::update(float dt)
{
	if (!_visible)
	{
		return;
	}

	if (_moveLeft)
	{
		this->setPositionX(this->getPositionX() - _speed * dt);
	}
	else
	{
		this->setPositionX(this->getPositionX() + _speed * dt);
	}
}

void Enemy::setMoveLeft(bool left)
{
	_moveLeft = left;
	this->setFlippedX(!left);
}

void Enemy::setSpeed(float speed)
{
	_speed = speed;
}