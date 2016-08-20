#pragma once

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
 
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

		cocostudio::timeline::ActionTimeline* getAction() { return _action; }
		void playAnimation(const std::string& aniname, bool loop = false);

	};
}