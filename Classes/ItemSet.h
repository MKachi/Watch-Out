//
//  ItemSet.hpp
//  Watch-Out
//
//  Created by 潘礼宁 on 2016/8/22.
//
//

#ifndef ItemSet_hpp
#define ItemSet_hpp

#include <stdio.h>
#include "ItemInformationDataSource.h"
namespace cocos2d {
    class ItemSet
    :public ItemInformationDataSource{
    private:
    public:
        ItemSet();
        ~ItemSet();
    };
}

#endif /* ItemSet_hpp */
