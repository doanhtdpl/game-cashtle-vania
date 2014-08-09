#ifndef __Info_SCENE_H__
#define __InFo_SCENE_H__
#include <string>
#include <vector>
//#include <d3dx9.h>
//Luu thong tin cua tung scene trong cac level.
//thong tin nay duoc doc len tu file
class InfoScene
{
public:
	InfoScene();
	InfoScene(std::vector<std::string> arr);
public:
	int level;//scene cua level nao
	int iD_Scene;//ID cua scene. Vi du. level1 scene 1: ID = 1
	int iD_Scene_Restart;//lay ID cua level duoc restart khi dang choi level nay
	int iD_Scene_Next;//lay ID cua scene tiep theo
	bool finalScene;//scene cuoi cung cua level do
	std::string bGPath;//duong dan toi background
	std::string bGQuadTree;//quadtree
	std::string mapPath;//duong dan toi map editor
	std::string mQuadTree;
	//D3DVECTOR _posSimon;//vi tri bat dau cua simon o scene nay
private:
};
#endif // !__InFo_SCENE_H__


#ifndef __MAP_LOADER_H__
#define __MAP_LOADER_H__
#include <hash_map>
#include "BackGround.h"

#define InFo_CSV_Path "..\\Resource\\file\\InfoScene.csv"

//chua list cac scene. Co cac phuong thuc de load background va load map
class MapLoader
{
private:
	static MapLoader* _instance;
protected:
	// key Sence = level * 10 + ID_Scene
	std::hash_map<int, InfoScene*> listInfoScene;//list chua thong tin cua tat ca scene
public:
	MapLoader();
	static MapLoader* getInstance();
	void readInfoSceneFromFile();//load thong tin tat ca scene len tu file
	InfoScene* getInfoSceneByKey(int keyScene);
};
#endif // !__MAP_LOADER_H__