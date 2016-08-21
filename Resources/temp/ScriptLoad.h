#pragma once

#include "cocos2d.h"
#include <string>
#include <vector>
#include "ElementSafe.h"

using namespace cocos2d;

class ScriptLoad
{
private:
	//�� ���� �ǵ��� �ʾƵ� �ǹǷ� �ּ��� ���� �ʴ´�!
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

	//�� ScriptLoad Ŭ������ ������
	static ScriptLoad* create();

	//�� ȭ�н��� ������ ������
	int getCount() { return count; };

	//�� ȭ�н��� ����ִ� vector�� ������
	std::vector<ElementSafe> getData()const { return Data; };

	//�� "Script/element.txt"�� ������ ������
	void Load();

};