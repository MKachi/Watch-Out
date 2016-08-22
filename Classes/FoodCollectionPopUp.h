//
//  CollectionPopUp.hpp
//  Watch-Out
//
//  Created by 潘礼宁 on 2016/8/21.
//
//
#pragma once

#ifndef FoodCollectionPopUp_hpp
#define FoodCollectionPopUp_hpp

#include "PopUp.h"
#include "cocos2d.h"
#include "ItemInformationDataSource.h"
#include "ItemSet.h"
#include "CollectionSelectPopUp.h"

namespace cocos2d{
    
    class FoodCollectionPopUp
    : public PopUp
    {
    protected:
        ItemInformationDataSource* data;
        int index;
        Sprite* namePicture;
        Sprite* picture;
        Button* left;
        Button* right;
        LabelTTF* positionLabel;
        Label* descriptionLabel;
        bool isDetail;
        void update();
    public:
        std::string getSetName(){
            return "Food";
        }
        bool init(Node* parent);
        CREATE_POPUP(FoodCollectionPopUp);
        //void update();
    };
};

#endif /* CollectionPopUp_hpp */
