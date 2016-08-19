#ifndef	_GameScene_H_
#define _GameScene_H_

#include "cocos2d.h"
#include "UserRule.h"

class GameScene 
	: public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(GameScene);
};

#endif