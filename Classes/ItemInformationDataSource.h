//
//  ItemInformationDataSource.hpp
//  Watch-Out
//
//  Created by 潘礼宁 on 2016/8/21.
//
//

#ifndef ItemInformationDataSource_hpp
#define ItemInformationDataSource_hpp
#include "ItemInformationCell.h"
#include <stdio.h>
namespace cocos2d{
class ItemInformationDataSource{
    private:
        std::vector<ItemInformationCell*> info;
        std::string setName;
    public:
        void initDataFromFile(std::string setName);
        ItemInformationDataSource();
        ItemInformationDataSource(std::string setName);
        ~ItemInformationDataSource();
        std::string getName(int atIndex){ return (info.at(atIndex))->name; }
        std::string getCountry(int atIndex){ return (info.at(atIndex))->country; }
        std::string getDescription(int atIndex){ return (info.at(atIndex))->description; }
        std::string getUrl(int atIndex){ return (info.at(atIndex))->url; }
        std::string getPictureDir(int atIndex){ return "collections/" + info.at(atIndex)->setdir + "/" + getName(atIndex) + ".png"; }
        std::string getNamePictureDir(int atIndex){return "collections/" + info.at(atIndex)->setdir + "/" + getName(atIndex) + "_Name.png";}
        size_t size(){ return info.size(); }
        void sort(){
            std::sort(info.begin(),info.end(),ItemInformationCell::compare);
        }
        void print(){
            for(int i = 0; i < info.size(); i ++){
                CCLOG("%s",info.at(i)->name.c_str());
            }
        }
    
    };
}
#endif /* ItemInformationDataSource_hpp */
