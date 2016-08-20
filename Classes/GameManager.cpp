#include "GameManager.h"

using namespace cocos2d;

static GameManager* _instance = nullptr;

GameManager* GameManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new GameManager();
	}
	return _instance;
}

void GameManager::destroy()
{
	if (_instance != nullptr)
	{
		delete _instance;
		_instance = nullptr;
	}
}

void GameManager::setSelectCountrys(const int index, Country country)
{
	_country[index] = country;
}
