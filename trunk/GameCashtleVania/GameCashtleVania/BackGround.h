#ifndef __BACK_GROUND_H__
#define __BACK_GROUND_H__

#include <hash_map>
#include <d3dx9.h>
#include <string>
#include <vector>
#include <iostream>

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
	std::hash_map<int, RECT*> _listTileRectRS;
public:
	BackGround();
	~BackGround();
	RECT* getRectResouceByIDTile(int IDTIle);
	RECT* getRectRSInHM(int IDTile);
	void readFromFile(std::string filePath);
	//std::vector<std::string> split(std::string s, char key);
	void drawBackGround();
	void addElement(std::vector<std::string> arr, int rowIndex);
	std::vector<std::string> BackGround::split(std::string s, char key);
};

#endif // !__BACK_GROUND_H__