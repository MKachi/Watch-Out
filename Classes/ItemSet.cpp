//
//  ItemSet.cpp
//  Watch-Out
//
//  Created by 潘礼宁 on 2016/8/22.
//
//

#include "ItemSet.h"

cocos2d::ItemSet::ItemSet(){
    initDataFromFile("C&F");
    initDataFromFile("Food");
    initDataFromFile("Landmark");
    print();
}