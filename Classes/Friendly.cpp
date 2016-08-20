﻿#include "Friendly.h"

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
	_die = false;
	this->setContentSize(Size(95, 155));
	countryImage(country);

	return true;
}

void Friendly::countryImage(Country country)
{
	switch (country)
	{
	case Country::Korea:
		_object = SkeletonObject::create("friendly/char-kr-pack.plist", "friendly/char-kr-sk.csb");
		break;

	case Country::China:
		_object = SkeletonObject::create("friendly/char-kr-pack.plist", "friendly/char-kr-sk.csb");
		break;

	case Country::Japen:
		_object = SkeletonObject::create("friendly/char-kr-pack.plist", "friendly/char-kr-sk.csb");
		break;
	}

	Size size = this->getContentSize();
	_object->getRoot()->setPosition(size.width / 2, size.height / 2 - 20);
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
	_move = move;
}

void Friendly::setDie(const bool die)
{
	_die = die;
}

void Friendly::setInLine(const bool inLine)
{
	_inLine = inLine;
}