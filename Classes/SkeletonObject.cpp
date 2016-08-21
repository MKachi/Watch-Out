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
	CC_SAFE_DELETE(result);

	return nullptr;
}

void SkeletonObject::playAnimation(const std::string& aniname, bool loop)
{
	_action->play(aniname, loop);
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
	addChildrenNode(_root);

	return true;
}

void SkeletonObject::addChildrenNode(Node* target)
{
	if (target->getChildrenCount() <= 0)
	{
		return;
	}
	else
	{
		for (int i = 0; i < target->getChildrenCount(); ++i)
		{
			_bones.push_back(target->getChildren().at(i));
			addChildrenNode(target->getChildren().at(i));
		}
	}
}