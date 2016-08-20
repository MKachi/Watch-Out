#include "Friendly.h"
#include "GameManager.h"

using namespace cocos2d;

Friendly::Friendly()
{	}

Friendly::~Friendly()
{	}

Friendly* Friendly::create(Country county)
{
	Friendly* result = new (std::nothrow) Friendly();
	if (result != nullptr && result->init(county) && result->initWithFile("TouchArea.png"))
	{
		result->autorelease();
		return result;
	}
	CC_SAFE_DELETE(result);
	return nullptr;
}

bool Friendly::init(Country country)
{
	_country = country;
	_move = false;
	this->setContentSize(Size(95, 155));
	countryImage(country);

	return true;
}

void Friendly::countryImage(Country country)
{
	switch (country)
	{
	case Country::Korea:
		_object = SkeletonObject::create("friendly/char-kr-pack.plist", "friendly/char-kr.csb");
		break;

	case Country::China:
		_object = SkeletonObject::create("friendly/char-kr-pack.plist", "friendly/char-kr.csb");
		break;

	case Country::Japen:
		_object = SkeletonObject::create("friendly/char-kr-pack.plist", "friendly/char-kr.csb");
		break;
	}

	Size size = this->getContentSize();
	_object->getRoot()->setPosition(size.width / 2, size.height / 2 - 20);
	_object->playAnimation("normal", true);
	this->addChild(_object);
}

void Friendly::setBackPosition(const Vec2& position)
{
	_backPosition = position;
}

void Friendly::setTouchID(const int id)
{
	_touchID = id;
}

void Friendly::setMove(const bool move)
{
	if (_die)
	{
		_move = false;
		return;
	}
	_move = move;
	if (_move)
	{
		GameManager::getInstance()->setCatchCount(GameManager::getInstance()->getCatchCount() + 1);
	}
	else
	{
		GameManager::getInstance()->setCatchCount(GameManager::getInstance()->getCatchCount() - 1);
	}
}

void Friendly::die(bool left)
{
//	this->setPosition(Vec2::ZERO);
	if (left)
	{
		auto dieMotion = _object->getAction();
		auto fadeAction = FadeOut::create(1000.0f);

		_object->playAnimation("deathToRight");
	//	_object->getRoot()->runAction(fadeAction);
	}
	else
	{
		_object->playAnimation("deathToLeft");
	}
	_die = true;
	GameManager::getInstance()->setLifeCount(GameManager::getInstance()->getLifeCount() - 1);
	if (GameManager::getInstance()->getLifeCount() <= 0)
	{
		GameManager::getInstance()->endGame();
	}
}

void Friendly::setInLine(const bool inLine)
{
	_inLine = inLine;
}