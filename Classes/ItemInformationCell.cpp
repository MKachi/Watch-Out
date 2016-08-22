//
//  ItemInformationCell.cpp
//  Watch-Out
//
//  Created by 潘礼宁 on 2016/8/21.
//
//

#include "ItemInformationCell.h"

cocos2d::ItemInformationCell::ItemInformationCell(ValueMap& v,string _setdir){
    name = v["name"].asString();
    country = v["country"].asString();
    description = v["description"].asString();
    url = v["url"].asString();
    unlocked = true;
    setdir = _setdir;
    CCLOG("%s\n",name.c_str());
}

 bool cocos2d::ItemInformationCell::compare (const ItemInformationCell* a, const ItemInformationCell* b )  {
    if(a->unlocked == true && b->unlocked == false)
        return true;
    if(b->unlocked == true && a->unlocked == false)
        return false;
    //CCLOG("a:%s\nb:%s\nans:%d\n",a->name.c_str(),b->name.c_str(),(int)(a->name<b->name));
    return a->name < b->name;
}
