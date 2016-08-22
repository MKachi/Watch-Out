//
//  ItemInformationCell.hpp
//  Watch-Out
//
//  Created by 潘礼宁 on 2016/8/21.
//
//

#ifndef ItemInformationCell_hpp
#define ItemInformationCell_hpp

#include <stdio.h>
#include <string>
namespace cocos2d {
    using std::string;
    struct ItemInformationCell{
        string name;
        string country;
        string description;
        string setdir;
        string url;
        bool unlocked;
        ItemInformationCell(ValueMap& v, string);
        
        /*bool operator < (const ItemInformationCell* b){
         if(unlocked == true && b->unlocked == false)
         return true;
         if(b->unlocked == true && unlocked == false)
         return false;
         CCLOG("a:%s\nb:%s\nans:%d\n",name.c_str(),b->name.c_str(),(int)(name < b->name));
         return name < b->name;
         }*/
        static bool compare (const ItemInformationCell* a, const ItemInformationCell* b );
    };
    
}
#endif /* ItemInformationCell_hpp */
