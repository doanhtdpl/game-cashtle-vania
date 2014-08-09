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

	// ID va RectRS cua no trong buc anh lon. ID = i * width + j
	std::hash_map<int, RECT> _listTileRectRS;

public:
	BackGround();
	~BackGround();

	//Truyen vao ID va lay Rect
	RECT* getRectResouceByIDTile(int IDTIle);

	//get Rect by ID
	RECT getRectInHM(int ID);
	void readMapFromFile(std::string filePath);
	void drawBackGround();

	void drawTileByID(int ID);
	void addElement(std::vector<std::string> arr, int rowIndex);
};

#endif // !__BACK_GROUND_H__