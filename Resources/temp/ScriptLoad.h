#pragma once

#include "cocos2d.h"
#include <string>
#include <vector>
#include "ElementSafe.h"

using namespace cocos2d;

class ScriptLoad
{
private:
	//┼ 여긴 건들지 않아도 되므로 주석은 달지 않는다!
	std::string script_temp;
	std::string image_temp;
	std::string name_temp;
	char temp_char[1024];
	int num_temp;
	std::vector<ElementSafe> Data;
	int count = 0;

public:
	ScriptLoad();
	virtual ~ScriptLoad();

	//┼ ScriptLoad 클래스를 생성함
	static ScriptLoad* create();

	//┼ 화학식의 갯수를 가져옴
	int getCount() { return count; };

	//┼ 화학식이 들어있는 vector를 가져옴
	std::vector<ElementSafe> getData()const { return Data; };

	//┼ "Script/element.txt"의 정보를 가져옴
	void Load();

};