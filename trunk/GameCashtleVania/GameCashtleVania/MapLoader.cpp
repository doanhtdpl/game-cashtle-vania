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
	this->bGQuadTree = arr.at(6);
	this->mapPath = arr.at(7);
	this->mQuadTree = arr.at(8);
	this->_bound = RECT();
}

RECT InfoScene::getBoundFromFile(std::vector<std::string> arr)
{
	int x = atoi(arr.at(2).c_str());
	int y = atoi(arr.at(3).c_str());
	int height = atoi(arr.at(4).c_str());
	int width = atoi(arr.at(5).c_str());

	this->_bound.left = x - width / 2;
	this->_bound.right = x + width / 2;
	this->_bound.bottom = y - height / 2;
	this->_bound.top = y + height / 2;

	return this->_bound;
}

RECT InfoScene::getBound()
{
	return this->_bound;
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
}

InfoScene* MapLoader::getInfoSceneByKey(int keyScene)
{
	return this->listInfoScene.find(keyScene)->second;
}
