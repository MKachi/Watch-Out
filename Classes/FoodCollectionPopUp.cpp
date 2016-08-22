//
//  CollectionPopUp.cpp
//  Watch-Out
//
//  Created by 潘礼宁 on 2016/8/21.
//
//

#include "FoodCollectionPopUp.h"


#include "PopUpManager.h"
#include "UserRule.h"

using namespace cocos2d;

bool FoodCollectionPopUp::init(Node* parent)
{
    std::string _setName = getSetName();
    isDetail = false;
    data = new ItemInformationDataSource(_setName);
    if (!PopUp::init(Color4B(0, 0, 0, 191)))
    {
        return false;
    }
    parent->addChild(this);
    
    auto backGround = Sprite::create("PopUpFrame.png");
    backGround->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    this->addChild(backGround);
    
    index=0;
    CCLOG("%s\n",data->getName(index).c_str());
    string tmpString = Value(index+1).asString() + "/" + Value((int)data->size()).asString();
    
    
    positionLabel = LabelTTF::create(tmpString, "fonts/verdana.ttf", 63.0f);
    positionLabel->setPosition(SCREEN_WIDTH / 2,SCREEN_HEIGHT/2 + 480);
    this->addChild(positionLabel,true,0);
    
    
    left = Button::create("teamSetting/Arrow.png", Color3B(125, 125, 125));
    left->click = [=]()
    {
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
        index = ((index - 1) + data->size() )% data->size();
        update();
    };
    left->setFlippedX(true);
    left->setPosition(SCREEN_WIDTH / 2 - 310, SCREEN_HEIGHT / 2);
    this->addChild(left, true, 0);
    this->registeButton(left);
    
    
    right = Button::create("teamSetting/Arrow.png", Color3B(125, 125, 125));
    right->click = [=]()
    {
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
        index = (index + 1) % data->size();
        update();
    };
    right->setPosition(SCREEN_WIDTH / 2 + 310, SCREEN_HEIGHT / 2);
    this->addChild(right, 1);
    this->registeButton(right);
    
    
    picture = Sprite::create (data->getPictureDir(index));
    picture->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 90);
    this->addChild(picture, true, 0); // Node, Button is true, zOther
    
    descriptionLabel = Label::createWithBMFont("fonts/DetailFont.fnt", data->getDescription(index));
    descriptionLabel->setDimensions(370, 550);
    descriptionLabel->setLineBreakWithoutSpace(false);
    descriptionLabel->setAlignment(TextHAlignment::LEFT);
    descriptionLabel->setVerticalAlignment(TextVAlignment::CENTER);
    descriptionLabel->setPosition(SCREEN_WIDTH / 2+5, SCREEN_HEIGHT / 2 + 90);
    descriptionLabel->setOpacity(0.0f);
    this->addChild(descriptionLabel,true,0);
    
    Button* pictureClickArea = Button::create(data->getPictureDir(index), Color3B(125, 125, 125));
    pictureClickArea->setOpacity(0.0f);
    pictureClickArea->click = [=]()
    {
        if(!data->isUnlocked(index)){
			SimpleAudioEngine::getInstance()->playEffect("sound/Error.ogg");
            return;
        }
        else if(!isDetail){
            picture->setColor(Color3B(125,125,125));
            descriptionLabel->setOpacity(255.0f);
        }
        else{
            picture->setColor(Color3B(255,255,255));
            descriptionLabel->setOpacity(0.0f);
        }
		SimpleAudioEngine::getInstance()->playEffect("sound/button.ogg");
        isDetail = !isDetail;
    };
    pictureClickArea->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 90);
    this->addChild(pictureClickArea,true,0);
    this->registeButton(pictureClickArea);
    
    
    namePicture = Sprite::create (data->getNamePictureDir(index));
    namePicture->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 -300);
    this->addChild(namePicture); // Node, Button is true, zOther
    
    Button* closeButton = Button::create("pause/Cancel.png", Color3B(125, 125, 125));
    closeButton->click = [=]()
    {
		SimpleAudioEngine::getInstance()->playEffect("sound/cancelButton.ogg");
        PopUpManager::getInstance()->closePopUp();
    };
    closeButton->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 430);
    this->addChild(closeButton, true, 0);
    this->registeButton(closeButton);
    
    update();
    
    
    return true;
}
void cocos2d::FoodCollectionPopUp::update(){
    if(data->isUnlocked(index)){
        string tmpString = Value(index+1).asString() + "/" + Value((int)data->size()).asString();
        positionLabel->setString(tmpString);
        
        picture->setTexture(data->getPictureDir(index));
        
        namePicture->setTexture(data->getNamePictureDir(index));
        
        descriptionLabel->setString(data->getDescription(index));
        
        picture->setColor(Color3B(255,255,255));
        
        descriptionLabel->setOpacity(0.0f);
        
        isDetail = false;
    }
    else{
        string tmpString = Value(index+1).asString() + "/" + Value((int)data->size()).asString();
        positionLabel->setString(tmpString);
        
        picture->setTexture("collections/Unknown.png");
        
        namePicture->setTexture("collections/Unknown_Name.png");
        
        descriptionLabel->setString("");
        
        picture->setColor(Color3B(255,255,255));
        
        descriptionLabel->setOpacity(0.0f);
        
        isDetail = false;
    }
}
