#include "FileUtils.h"
#include "ManageTexture.h"
#include <fstream>
#include "SimonFactory.h"

using namespace std;

FileUtils* FileUtils::_instance = NULL;

FileUtils* FileUtils::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new FileUtils();
	}
	return _instance;
}

FileUtils::FileUtils() 
{

}

//doc file csv va luu objectFactory vao list
void FileUtils::ReadFileCSV(char* fileName, ObjectFactory* objFactory)
{
	string line;
	ifstream* myfile = new ifstream(fileName);
	if (myfile->is_open())
	{
		//lay dong dau tien: key (idimage,link)
		std::getline(*myfile, line, '\n');

		while ( !myfile->eof()) 
		{
			if (getline(*myfile, line))
			{
				vector<string> arr = Split(line, ',');
				int ID_Object = atoi(arr[0].c_str());
				objFactory->addInfo(arr);
				//them objectfactory vao list
				this->list_ObjFactory[ID_Object] = objFactory;
				//this->list_ObjFactory->insert(std::pair<int, ObjectFactory*>(ID_Object, objFactory));
			}
		}
	}
}

//load tat ca file CSV va luu vao list ObjectFactory
void FileUtils::LoadCSV()
{
	this->ReadFileCSV(fileSimon, SimonFactory::getInstance());
}

void FileUtils::ReadFileMap()
{

}

void FileUtils::ReadFileImage()
{
	string line;
	ifstream* myfile = new ifstream(fileImage);
	if (myfile->is_open())
	{
		//lay dong dau tien: key (idimage,link)
		getline(*myfile, line);

		while ( !myfile->eof() ) 
		{
			if (getline(*myfile, line))
			{
				//IDImage - Link

				vector<string> arr = Split(line, ',');
				int ID_Image = atoi(arr[0].c_str());
				string linkResource = arr[1];
				ManageTexture::getInstance()->createTextureByFileName(ID_Image, linkResource);
			}
		}
	}
}

//cat 1 dong thanh cac chu cach nhau boi key: s = so tuan hoang. key = " "--> "so" - "tuan" - "hoang"
vector<string> FileUtils::Split(string s, char key)
{
	vector<string> arr;
	string sTemp = "";
	int index = 0;
	while(index < s.length())
	{
		while(s[index] != key && index < s.length() && s[index] != ' ')
		{
			sTemp += s[index];
			index++;
		}
		if(sTemp.size() > 0)
			arr.push_back(sTemp);
		index++;
		sTemp.clear();
	}
	return arr;
}