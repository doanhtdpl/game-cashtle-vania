#include "MapLoader.h"
#include "utils.h"
#include "FileUtils.h"

InfoScene::InfoScene()
{

}

InfoScene::InfoScene(std::vector<std::string> arr)
{
	this->level = atoi(arr.at(0).c_str());
	this->iD_Scene = atoi(arr.at(1).c_str());
	this->iD_Scene_Restart = atoi(arr.at(2).c_str());
	this->iD_Scene_Next = atoi(arr.at(3).c_str());
	this->finalScene = atoi(arr.at(4).c_str());
	this->bGPath = arr.at(5);
	this->bGQuadTree = arr.at(6);;
	this->mapPath = arr.at(7);;
	this->mQuadTree = arr.at(8);;
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
	std::vector<std::vector<std::string>> info = FileUtils::readFile(InFo_CSV_Path, ',');
	std::vector<std::vector<std::string>>::iterator it;
	std::vector<std::string> arr;
	InfoScene* infoScene;
	it = info.begin();
	it++;
	while (it != info.end())
	{
		arr = *it++;
		infoScene = new InfoScene(arr);
		int keyScene = infoScene->level * 10 + infoScene->iD_Scene;
		this->listInfoScene[keyScene] = infoScene;
	}
	//string line;
	//ifstream* myfile = new ifstream(InFo_CSV_Path);
	//if (myfile->is_open())
	//{
	//	//lay dong dau tien: key (idimage,link)
	//	std::getline(*myfile, line, '\n');

	//	int _level;
	//	int _idScene;
	//	int _iD_Scene_Restart;
	//	int _iD_Scene_Next;
	//	bool _finalScenel;
	//	std::string _bGPath;
	//	std::string _mapPath;
	//	while ( !myfile->eof()) 
	//	{
	//		if (getline(*myfile, line))
	//		{
	//			vector<string> arr = split(line, ',');
	//			_level = atoi(arr[0].c_str());
	//			_idScene = atoi(arr[1].c_str());
	//			_iD_Scene_Restart = atoi(arr[2].c_str());
	//			_iD_Scene_Next = atoi(arr[3].c_str());
	//			_finalScenel = (bool)(atoi(arr[4].c_str()));
	//			
	//			std::string str = arr[5];

	//			/*_bGPath = alloca(arr[5].size() + 1);

	//			_bGPath = new char[arr[5].length() + 1];
	//			std::copy(arr[5].begin(), arr[5].end(), _bGPath);
	//			_bGPath[arr[5].length()] = '\0';

	//			_mapPath = new char[arr[6].length() + 1];
	//			std::copy(arr[6].begin(), arr[6].end(), _mapPath);
	//			_mapPath[arr[6].length()] = '\0';*/
	//			_bGPath = arr[5];
	//			_mapPath = arr[6];
	//			//tao info scene
	//			InfoScene* infoScene = new InfoScene(_level, _idScene, _iD_Scene_Restart, _iD_Scene_Next, _finalScenel, _bGPath, _mapPath);
	//			
	//			int keyScene = _level * 10 + _idScene;
	//			this->listInfoScene[keyScene] = infoScene;
	//			//this->list_ObjFactory->insert(std::pair<int, ObjectFactory*>(ID_Object, objFactory));
	//		}
	//	}
	//}
}

InfoScene* MapLoader::getInfoSceneByKey(int keyScene)
{
	return this->listInfoScene.find(keyScene)->second;
}
