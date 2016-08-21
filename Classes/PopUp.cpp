#include "PopUp.h"
#include "UserRule.h"

using namespace cocos2d;

bool PopUp::init(PopUpInfo* info)
{
	for (int i = 0; i < info->_children.size(); ++i)
	{
		this->addChild(info->_children[i], info->_depth[i]);
	}

	for (int i = 0; i < info->_touchObject.size(); ++i)
	{
		_touchObject.push_back(info->_touchObject[i]);
	}

	delete info;
	
	return true;
}

PopUp::PopUp()
{	}

PopUp::~PopUp()
{	}

PopUp* PopUp::create(const std::string& filename)
{
	PopUp* result = new (std::nothrow) PopUp();
	if (result != nullptr && result->initWithFile(filename))
	{
		result->autorelease();
		result->setVisible(false);
		return result;
	}
	CC_SAFE_DELETE(result);
	return nullptr;
}

PopUp* PopUp::create(PopUpInfo* info)
{
	info->init();
	PopUp* result = new (std::nothrow) PopUp();
	if (result != nullptr && result->initWithFile("PopUpFrame.png") && result->init(info))
	{
		result->autorelease();
		result->setVisible(false);
		return result;
	}
	CC_SAFE_DELETE(result);
	return nullptr;
}

void PopUp::addBlackScreen()
{
	if (_screen == nullptr)
	{
		_screen = LayerColor::create(Color4B(0, 0, 0, 191), SCREEN_WIDTH, SCREEN_HEIGHT);
		_screen->setPosition(0, 0);
		this->getParent()->addChild(_screen, this->getZOrder() - 1);
	}
}

void PopUp::show()
{
	if (_screen != nullptr)
	{
		_screen->setVisible(true);
	}
	this->setVisible(true);
}

void PopUp::hide()
{
	if (_screen != nullptr)
	{
		_screen->setVisible(false);
	}
	this->setVisible(false);
}

void PopUp::begin(Vec2 touchPoint)
{
	if (!this->isVisible())
	{
		return;
	}

	Vec2 location = this->convertToNodeSpace(touchPoint);
	for (int i = 0; i < _touchObject.size(); ++i)
	{
		_touchObject[i]->begin(location);
	}
}

void PopUp::ended(Vec2 touchPoint)
{
	if (!this->isVisible())
	{
		return;
	}

	Vec2 location = this->convertToNodeSpace(touchPoint);
	for (int i = 0; i < _touchObject.size(); ++i)
	{
		_touchObject[i]->ended(location);
	}
}
