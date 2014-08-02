#include "MapLoader.h"
#include <fstream>
#include "utils.h"

InfoScene::InfoScene()
{

}

InfoScene::InfoScene(int _level, int _idScene, int _iDSceneRestart, int _iDSceneNext, 
						bool _finalScene, std::string _bGPath, std::string _mapPath)
{
	this->level = _level;
	this->iD_Scene = _idScene;
	this->iD_Scene_Restart = _iDSceneRestart;
	this->iD_Scene_Next = _iDSceneNext;
	this->finalScene = _finalScene;
	this->bGPath = _bGPath;
	this->mapPath = _mapPath;
}

MapLoader* MapLoader::_instance = NULL;

MapLoader* MapLoader::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new MapLoader();
	}

	return _instance;
}

MapLoader::MapLoader()
{

}

void MapLoader::readInfoSceneFromFile()
{
	string line;
	ifstream* myfile = new ifstream(InFo_CSV_Path);
	if (myfile->is_open())
	{
		//lay dong dau tien: key (idimage,link)
		std::getline(*myfile, line, '\n');

		int _level;
		int _idScene;
		int _iD_Scene_Restart;
		int _iD_Scene_Next;
		bool _finalScenel;
		std::string _bGPath;
		std::string _mapPath;
		while ( !myfile->eof()) 
		{
			if (getline(*myfile, line))
			{
				vector<string> arr = split(line, ',');
				_level = atoi(arr[0].c_str());
				_idScene = atoi(arr[1].c_str());
				_iD_Scene_Restart = atoi(arr[2].c_str());
				_iD_Scene_Next = atoi(arr[3].c_str());
				_finalScenel = (bool)(atoi(arr[4].c_str()));
				
				std::string str = arr[5];

				/*_bGPath = alloca(arr[5].size() + 1);

				_bGPath = new char[arr[5].length() + 1];
				std::copy(arr[5].begin(), arr[5].end(), _bGPath);
				_bGPath[arr[5].length()] = '\0';

				_mapPath = new char[arr[6].length() + 1];
				std::copy(arr[6].begin(), arr[6].end(), _mapPath);
				_mapPath[arr[6].length()] = '\0';*/
				_bGPath = arr[5];
				_mapPath = arr[6];
				//tao info scene
				InfoScene* infoScene = new InfoScene(_level, _idScene, _iD_Scene_Restart, _iD_Scene_Next, _finalScenel, _bGPath, _mapPath);
				
				int keyScene = _level * 10 + _idScene;
				this->listInfoScene[keyScene] = infoScene;
				//this->list_ObjFactory->insert(std::pair<int, ObjectFactory*>(ID_Object, objFactory));
			}
		}
	}
}

InfoScene* MapLoader::getInfoSceneByKey(int keyScene)
{
	return this->listInfoScene.find(keyScene)->second;
}

std::vector<std::string> MapLoader::split(std::string s, char key)
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