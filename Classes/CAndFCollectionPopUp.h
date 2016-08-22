//
//  CollectionPopUp.hpp
//  Watch-Out
//
//  Created by 潘礼宁 on 2016/8/21.
//
//
#pragma once

#ifndef CAndFCollectionPopUp_hpp
#define CAndFCollectionPopUp_hpp

#include "PopUp.h"
#include "cocos2d.h"
#include "ItemInformationDataSource.h"
#include "ItemSet.h"
#include "CollectionSelectPopUp.h"

namespace cocos2d{
    
    class CAndFCollectionPopUp
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
            return "C&F";
        }
        bool init(Node* parent);
        CREATE_POPUP(CAndFCollectionPopUp);
        //void update();
    };
};

#endif /* CollectionPopUp_hpp */
