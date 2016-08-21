#include "ScriptLoad.h"

ScriptLoad::ScriptLoad()
{

}

ScriptLoad::~ScriptLoad()
{

}

ScriptLoad* ScriptLoad::create()
{
	ScriptLoad* KS_ScriptLoad = new ScriptLoad();

	if (KS_ScriptLoad)
	{
		return KS_ScriptLoad;
	}
	delete KS_ScriptLoad;

	return nullptr;
}

void ScriptLoad::Load()
{
	FileUtils* F_Utils = FileUtils::getInstance();
	auto F_Path = F_Utils->fullPathForFilename("script/e_script.txt");
	auto F_Data = F_Utils->getStringFromFile(F_Path);

	std::stringstream file(F_Data);

	if (!file == NULL)
	{
		while (!file.eof())
		{
			file >> script_temp;

			if (script_temp == "def")
			{
				file >> script_temp;
				Data.push_back(ElementSafe(script_temp));
			}

			if (script_temp == "Image")
			{
				file >> image_temp;
				Data[count].setImage(image_temp);
			}

			if (script_temp == "Chemical")
			{
				while (1)
				{
					file >> script_temp;

					if (script_temp == "name")
					{
						file >> name_temp;
					}

					if (script_temp == "num")
					{
						file >> script_temp;
						num_temp = atoi(script_temp.c_str());
					}

					if (script_temp == "break")
					{
						Data[count].addChmical(Chemical(name_temp, num_temp));
					}

					if (script_temp == "ex")
					{
						while (1)
						{
							file.getline(temp_char, 1024);
							script_temp = temp_char;
							if (script_temp == "xe\r")
							{
								break;
							}
							Data[count].setEx(temp_char);
						}
					}

					if (script_temp == "used")
					{
						while (1)
						{
							file.getline(temp_char, 1024);
							script_temp = temp_char;
							if (script_temp == "un\r")
							{
								break;
							}
							Data[count].setUsed(temp_char);
						}
					}

					if (script_temp == "end")
					{
						count++;
						break;
					}
				}
			}

			if (file.eof())
			{
				break;
			}
		}
	}
}