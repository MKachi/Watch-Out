#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
/*
SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
frameCache->addSpriteFramesWithFile("friendly/char-kr-pack.plist");
auto rootNode = CSLoader::createNode("friendly/char-kr-sk.csb");
cocostudio::timeline::ActionTimeline* action = CSLoader::createTimeline("friendly/char-kr-sk.csb");
action->gotoFrameAndPlay(0, true);
rootNode->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
rootNode->runAction(action);
this->addChild(rootNode, 199);
*/
namespace cocos2d
{
	class SkeletonObject
		: public Node
	{
	protected:
		Node* _root;
		cocostudio::timeline::ActionTimeline* _action;

		bool init(const std::string& plist, const std::string& csb);

		SkeletonObject();
		virtual ~SkeletonObject();

	public:
		static SkeletonObject* create(const std::string& plist, const std::string& csb);
		Node* getRoot() { return _root; }

	};
}