#include "Floor.h"
#include "Friendly.h"

using namespace cocos2d;

Floor::Floor()
{	}

Floor::~Floor()
{	}

Floor* Floor::create(const std::string& filename, const float floorY)
{
	Floor* result = new (std::nothrow) Floor();
	if (result != nullptr && result->initWithFile(filename) && result->init(floorY))
	{
		result->autorelease();
		return result;
	}
	return nullptr;
}

bool Floor::init(const float floorY)
{
	_floorY = floorY;

	return true;
}

void Floor::initArea(Rect dropArea, Node* layer)
{
	_dropArea = Sprite::create();
	_dropArea->setOpacity(0.0f);
	_dropArea->setPosition(this->getPosition().x, this->getPosition().y);
	_dropArea->setAnchorPoint(Vec2(0.5f, 0.0f));
	_dropArea->setContentSize(dropArea.size);
	_dropArea->setTextureRect(dropArea);
	layer->addChild(_dropArea, 99);
}

void Floor::dropCheck(Friendly* friendly)
{
	if (friendly->isMove() && !friendly->isInLine())
	{
		Rect dropArea = _dropArea->getBoundingBox();

		if (dropArea.intersectsRect(friendly->getBoundingBox()))
		{
			friendly->setPositionY(_floorY);
			friendly->setInLine(true);
			friendly->setMove(false);
		}
	}
}