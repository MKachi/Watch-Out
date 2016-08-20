#include "SkeletonObject.h"

using namespace cocos2d;

SkeletonObject::SkeletonObject()
{	}

SkeletonObject::~SkeletonObject()
{	}

SkeletonObject* SkeletonObject::create(const std::string& plist, const std::string& csb)
{
	SkeletonObject* result = new (std::nothrow) SkeletonObject();
	if (result != nullptr && result->init(plist, csb))
	{
		result->autorelease();
		return result;
	}
	return nullptr;
}

bool SkeletonObject::init(const std::string& plist, const std::string& csb)
{
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(plist);
	_root = CSLoader::createNode(csb);

	_action = CSLoader::createTimeline(csb);
	_action->gotoFrameAndPlay(0, true);
	_root->runAction(_action);
	this->addChild(_root);

	return true;
}