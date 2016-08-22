//
//  CollectionSelectPopUp.cpp
//  Watch-Out
//
//  Created by 潘礼宁 on 2016/8/22.
//
//

#include "CollectionSelectPopUp.h"

bool cocos2d::CollectionSelectPopUp::init(Node* parent)
{
    if (!PopUp::init(Color4B(0, 0, 0, 191)))
    {
        return false;
    }
    parent->addChild(this);
    
	Sprite* background = Sprite::create("PopUpFrame.png");
	background->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->addChild(background);

    Button* foodButton = Button::create("collections/Food Button.png", Color3B(125, 125, 125));
    foodButton->click = [=]()
    {
		SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
        PopUpManager::getInstance() -> openPopUp(FoodCollectionPopUp::create(parent));
        // Show TeamSetting
    };
    foodButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 370);
    this->addChild(foodButton, true, 0);
    this->registeButton(foodButton);
    
    Button* landmarkButton = Button::create("collections/Landmark Button.png", Color3B(125, 125, 125));
    landmarkButton->click = [=]()
    {
		SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
        PopUpManager::getInstance() -> openPopUp(LandmarkCollectionPopUp::create(parent));
    };
    landmarkButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 70);
    this->addChild(landmarkButton, true, 0);
    this->registeButton(landmarkButton);
    
    Button* CAndFButton = Button::create("collections/Clothes and Festival Button.png", Color3B(125, 125, 125));
    CAndFButton->click = [=]()
    {
		SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
        PopUpManager::getInstance() -> openPopUp(CAndFCollectionPopUp::create(parent));
        // Show RandomBox
    };
    CAndFButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 230);
    this->addChild(CAndFButton, true, 0); // Node, Button is true, zOther
    this->registeButton(CAndFButton);
    
    Button* closeButton = Button::create("collections/Cancel.png", Color3B(125, 125, 125));
    closeButton->click = [=]()
    {
		SimpleAudioEngine::getInstance()->playEffect("sound/cancelButton.mp3");
        PopUpManager::getInstance()->closePopUp();
    };
    closeButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 430);
    this->addChild(closeButton, true, 0);
    this->registeButton(closeButton);
    
    return true;
}
