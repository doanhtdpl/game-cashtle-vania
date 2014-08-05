#ifndef __BACK_GROUND_H__
#define __BACK_GROUND_H__

#include <hash_map>
#include <d3dx9.h>
#include <string>
#include <vector>
#include <iostream>
#include "ObjectGame.h"

class BackGround
{
private:
	int** _matrix;
	int _tileHeight;
	int _tileWidth;
	int _mapHeight;
	int _mapWidth;
	int _column;// tong so tile tren 1 dong cua background; 17
	int _IDImage;

	// ID cua tile va Rect* cua no trong buc anh lon.
	std::hash_map<int, RECT*> _listTileRectRS;

	
public:
	//ID Object va ObjectGame tuong ung
	std::vector<ObjectGame*> _listObjectInMap;

	BackGround();
	~BackGround();
	RECT* getRectResouceByIDTile(int IDTIle);
	RECT* getRectRSInHM(int IDTile);
	void readFromFile(std::string filePath);
	//std::vector<std::string> split(std::string s, char key);
	void drawBackGround();
	void addElement(std::vector<std::string> arr, int rowIndex);
	void addObject(std::vector<std::string> arr, int rowIndex);
	std::vector<std::string> BackGround::split(std::string s, char key);

	void fixMapBackground(std::string filePath);
};

#endif // !__BACK_GROUND_H__