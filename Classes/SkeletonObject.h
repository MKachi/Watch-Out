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
		std::vector<Node*> _bones;
		cocostudio::timeline::ActionTimeline* _action;

		bool init(const std::string& plist, const std::string& csb);

		void addChildrenNode(Node* target);

		SkeletonObject();
		virtual ~SkeletonObject();

	public:
		static SkeletonObject* create(const std::string& plist, const std::string& csb);

		std::vector<Node*>& getBones() { return _bones; }
		Node* getRoot() { return _root; }

		void playAnimation(const std::string& aniname, bool loop = false);

	};
}