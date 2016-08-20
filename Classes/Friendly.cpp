#include "Friendly.h"

using namespace cocos2d;

Friendly::Friendly()
{	}

Friendly::~Friendly()
{	}

Friendly* Friendly::create(Country county)
{
	Friendly* result = new (std::nothrow) Friendly();
	if (result != nullptr && result->initWithFile(countryImage(county)) && result->init(county))
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
	return true;
}

std::string Friendly::countryImage(Country country)
{
	switch (country)
	{
	case Country::Korea:
		return "Temp_Char_KR.png";
	case Country::China:
		return "Temp_Char_KR.png";
	case Country::Japen:
		return "Temp_Char_KR.png";
	}
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