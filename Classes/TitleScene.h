#pragma once

#include "cocos2d.h"
#include "UserRule.h"
#include "Button.h"
#include "PopUp.h"

class TitleScene
	: public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(TitleScene);

private:
	cocos2d::Sprite* backGround;
	cocos2d::Sprite* titleText;
	cocos2d::Button* startButton;
	cocos2d::Button* mainPopUpButton;
	cocos2d::Button* helpPopUpButton;

	cocos2d::PopUp* mainPopUp;
	std::vector<cocos2d::PopUp*> popUps;

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) override;
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;

	void update(float dt);

};