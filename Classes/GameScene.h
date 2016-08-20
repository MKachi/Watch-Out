#pragma once

#include "cocos2d.h"
#include "UserRule.h"
#include "Floor.h"
#include "Friendly.h"
#include "EnenySpawner.h"

class GameScene 
	: public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(GameScene);

	cocos2d::Sprite* backGround;

	// PauseButton
	cocos2d::Sprite* pauseButton;
	cocos2d::Color3B pauseOriginColor;
	cocos2d::Color3B pauseClickColor;
	int pauseTouchID;

	cocos2d::Floor* floor[3];
	cocos2d::Friendly* friendly[3];

	cocos2d::EnemySpawner* spawner;
	cocos2d::SpawnPoint spawnPoint;

	void showPausePopUp();
	void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
	void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
	void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;

	void Update(float dt);

};