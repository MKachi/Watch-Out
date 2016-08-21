#pragma once

#include "cocos2d.h"
#include "UserRule.h"
#include "Floor.h"
#include "GameManager.h"
#include "EnenySpawner.h"
#include "Button.h"

class GameScene
	: public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(GameScene);

private:
	cocos2d::Sprite* backGround[3];
	bool backGroundAni[3];

	cocos2d::Color3B ClickColor;
	cocos2d::Color3B originColor;

	// PauseButton
	cocos2d::Button* pauseButton;

	// PausePopUp
	cocos2d::LayerColor* popUpLayer;
	cocos2d::Sprite* popUpFrame;

	cocos2d::Button* menuButton;
	cocos2d::Button* cancelButton;
	cocos2d::Button* retryButton;

	cocos2d::Floor* floor[3];
	cocos2d::Friendly* friendly[3];

	cocos2d::EnemySpawner* spawner;
	cocos2d::SpawnPoint spawnPoint[6];

	// result popUp font size 44
	cocos2d::LayerColor* resultLayer;
	cocos2d::Sprite* resultFrame;
	cocos2d::Sprite* resultTitle;
	cocos2d::Sprite* trophy;
	cocos2d::LabelTTF* bestScore;
	cocos2d::LabelTTF* score;
	cocos2d::LabelTTF* obtain;
	cocos2d::Button* confirmButton;
	void setResultPopUp(bool active);
	void downResultPopUp(float dt);

	void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
	void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
	void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;

	void update(float dt);
	void scoreUp(float dt);

	float delayCount = 0.0f;
	void delayTimer(float dt);

	std::string intToString(int value);

};