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
	RECT* GetRectResouceByIDTile(int IDTIle);
	RECT* GetRectRSInHM(int IDTile);
	void ReadFromFile(char* filePath);
	std::vector<std::string> Split(std::string s, char key);
	void DrawBackGround();
	void AddElement(std::vector<std::string> arr, int rowIndex);

};

#endif // !__BACK_GROUND_H__