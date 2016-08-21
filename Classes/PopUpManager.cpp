#include "PopUpManager.h"

using namespace cocos2d;

static PopUpManager* _instance = nullptr;

PopUpManager* PopUpManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new PopUpManager();
	}
	return _instance;
}

void PopUpManager::destroy()
{
	if (_instance != nullptr)
	{
		delete _instance;
		_instance = nullptr;
	}
}

void PopUpManager::openPopUp(PopUp* popUp)
{
	if (!_stack.empty())
	{
		_stack.top()->setVisible(false);
	}
	_stack.push(popUp);
	_stack.top()->setVisible(true);
}

void PopUpManager::closePopUp()
{
	if (_stack.empty())
	{
		return;
	}
	_stack.top()->setVisible(false);
	_stack.pop();
	if (!_stack.empty())
	{
		_stack.top()->setVisible(true);
	}
}

PopUp* PopUpManager::getCurrentShowPopUp()
{
	if (_stack.empty())
	{
		return nullptr;
	}
	return _stack.top();
}
