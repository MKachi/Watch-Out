//
//  CollectionSelectPopUp.hpp
//  Watch-Out
//
//  Created by 潘礼宁 on 2016/8/22.
//
//

#ifndef CollectionSelectPopUp_hpp
#define CollectionSelectPopUp_hpp

#include "cocos2d.h"
#include <stdio.h>
#include "PopUp.h"
#include "UserRule.h"
#include "PopUpManager.h"
#include "LandmarkCollectionPopUp.h"
#include "CAndFCollectionPopUp.h"
#include "FoodCollectionPopUp.h"
#include <string>


namespace cocos2d
{
    class CollectionSelectPopUp
    : public PopUp
    {
    private:
    public:
        bool init(Node* parent);
        CREATE_POPUP(CollectionSelectPopUp);
    };
}

#endif /* CollectionSelectPopUp_hpp */
