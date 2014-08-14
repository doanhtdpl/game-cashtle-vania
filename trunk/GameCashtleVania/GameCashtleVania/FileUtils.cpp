#include "FileUtils.h"
#include "ManageTexture.h"
#include <fstream>
#include "SimonFactory.h"
#include "IronRodFac.h"
#include "LightFactory.h"
#include "WeaponFactory.h"
#include "ItemFactory.h"

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
void FileUtils::readFileCSV(char* fileName, ObjectFactory* objFactory)
{
	//string line;
	//ifstream* myfile = new ifstream(fileName);
	//if (myfile->is_open())
	//{
	//	//lay dong dau tien: key (idimage,link)
	//	std::getline(*myfile, line, '\n');

	//	while ( !myfile->eof()) 
	//	{
	//		if (getline(*myfile, line))
	//		{
	//			vector<string> arr = split(line, ',');
	//			int ID_Object = atoi(arr[0].c_str());
	//			objFactory->addInfo(arr);
	//			//them objectfactory vao list
	//			this->list_ObjFactory[ID_Object] = objFactory;
	//			//this->list_ObjFactory->insert(std::pair<int, ObjectFactory*>(ID_Object, objFactory));
	//		}
	//	}
	//}

	vector<vector<string>> info = readFile(fileName, ',');

	vector<vector<string>>::iterator it;
	vector<string> arr;
	it = info.begin();

	//bo dong dau tien. nen chay tu 1 - >
	it++;
	while (it != info.end())
	{
		arr = *it;
		int ID_Object = atoi(arr[0].c_str());
		objFactory->addInfo(arr);
		//them objectfactory vao list
		this->list_ObjFactory[ID_Object] = objFactory;

		it++;
	}
}

//load tat ca file CSV va luu vao list ObjectFactory
void FileUtils::loadCSV()
{
	this->readFileCSV(fileSimon, SimonFactory::getInstance());
	this->readFileCSV(fileIronRod, IronRodFac::getInstance());
	this->readFileCSV(fileLight, LightFactory::getInstance());
    this->readFileCSV(fileWeapon, WeaponFactory::getInstance());
    this->readFileCSV(fileItem, ItemFactory::getInstance());
}

void FileUtils::readFileMap()
{

}

void FileUtils::readFileImage()
{
	//string line;
	//ifstream* myfile = new ifstream(fileImage);
	//if (myfile->is_open())
	//{
	//	//lay dong dau tien: key (idimage,link)
	//	getline(*myfile, line);

	//	while ( !myfile->eof() ) 
	//	{
	//		if (getline(*myfile, line))
	//		{
	//			//IDImage - Link

	//			vector<string> arr = split(line, ',');
	//			int ID_Image = atoi(arr[0].c_str());
	//			string linkResource = arr[1];
	//			ManageTexture::getInstance()->createTextureByFileName(ID_Image, linkResource);
	//		}
	//	}
	//}

	vector<vector<string>> info = readFile(fileImage, ',');
	
	vector<vector<string>>::iterator it;
	vector<string> arr;
	it = info.begin();

	//bo dong dau tien. nen chay tu 1 - >
	it++;
	while (it != info.end())
	{
		arr = *it;
		int ID_Image = atoi(arr[0].c_str());
		string linkResource = arr[1];
		ManageTexture::getInstance()->createTextureByFileName(ID_Image, linkResource);
		it++;//tang bien it len.
	}
}

//cat 1 dong thanh cac chu cach nhau boi key: s = so tuan hoang. key = " "--> "so" - "tuan" - "hoang"
vector<string> FileUtils::split(string s, char key)
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

std::vector<std::vector<std::string>> FileUtils::readFile(std::string filePath, char key)
{
	std::vector<std::vector<std::string>> info;
	vector<string> arr;
	string line;
	ifstream* myfile = new ifstream(filePath);
	if (myfile->is_open())
	{
		while ( !myfile->eof() ) 
		{
			if (getline(*myfile, line))
			{
				//doc tung dong. cat ra va dua vao info
				arr = split(line, key);
				info.push_back(arr);
			}
		}
	}
	return info;
}