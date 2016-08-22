//
//  ItemInformationDataSource.cpp
//  Watch-Out
//
//  Created by 潘礼宁 on 2016/8/21.
//
//

#include "ItemInformationDataSource.h"
cocos2d::ItemInformationDataSource::ItemInformationDataSource(){
    
}
cocos2d::ItemInformationDataSource::ItemInformationDataSource(std::string _setName)
{
    setName = _setName;
    initDataFromFile(setName);
}
void cocos2d::ItemInformationDataSource::initDataFromFile(std::string setName){
    FileUtils* F_Utils = FileUtils::getInstance();
    auto F_Path = F_Utils->fullPathForFilename("collections/"+setName+".plist");
    ValueVector array = F_Utils->getValueVectorFromFile(F_Path);
    for(int i = 0, j = (int)array.size();i < j ; i ++){
        ValueMap tmp = (ValueMap)array.at(i).asValueMap();
        info.push_back(new ItemInformationCell(tmp,setName));
    }
    sort();
}
cocos2d::ItemInformationDataSource::~ItemInformationDataSource(){
    
}
