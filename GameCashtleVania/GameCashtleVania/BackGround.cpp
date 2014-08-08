#include "BackGround.h"
#include "ManageSprite.h"
#include <fstream>
#include "GroundBGFac.h"
#include "FileUtils.h"

using namespace std;

BackGround::BackGround()
{
	this->_matrix = NULL;
	this->_IDImage = 2002;
}

void BackGround::readFromFile(std::string filePath)
{
	this->_column = 17;

	std::string line;
	std::vector<std::string> arr;
	std::ifstream* myfile = new std::ifstream(filePath);

	if (myfile->is_open())
	{
		//doc dong dau tien lay chi so dong va cot cua ma tran
		getline(*myfile, line);
		
		//chuan hoa dong dau tien. Bo nhung ki tu khong phai so
		int k = 0;
		while(line[k] < 48 || line[k] > 57)
		{
			line.erase(line.begin());
		}

		arr = FileUtils::split(line, '\t');
		_mapWidth = atoi(arr[0].c_str()); 
		_mapHeight = atoi(arr[1].c_str());

		this->_matrix = new int*[_mapWidth];
		for (int i = 0; i < _mapWidth; i++)
		{
			this->_matrix[i] = new int[_mapHeight];
		}

		//doc dong thu hai lay do dai va rong cua tile map
		std::getline(*myfile, line);
		arr = FileUtils::split(line, '\t');
		this->_tileHeight = atoi(arr[0].c_str()); 
		this->_tileWidth = atoi(arr[1].c_str());

		int row = 0;
		while ( !myfile->eof()) 
		{
			if (std::getline(*myfile, line))
			{
				arr = FileUtils::split(line, '\t');
				addElement(arr, row);
				row++;
				//them objectfactory vao list
			}
		}
	}
}



// lay rectResource cua IDTile tren background
RECT* BackGround::getRectResouceByIDTile(int IDTile)
{
	RECT* rectRS = new RECT();

	int x = (IDTile % this->_column) * this->_tileWidth;
	int y = (IDTile / this->_column) * this->_tileHeight;

	rectRS->left = x;
	rectRS->right = x + this->_tileWidth;
	rectRS->top = y;
	rectRS->bottom = y + this->_tileHeight;

	return rectRS;
}

RECT* BackGround::getRectRSInHM(int IDTile)
{
	return this->_listTileRectRS.find(IDTile)->second;
}

void BackGround::drawBackGround()
{
	int IDTile;

	//ve tat ca hinh anh khong phia doi tuong ground
	for (int i = 0; i < _mapWidth; i++)
	{
		for (int j = 0; j < _mapHeight; j++)
		{
			IDTile = _matrix[i][j];
			
			if (IDTile < 600)
			{
				// vi tri top left cua tile hien tai tren the gioi game
				D3DXVECTOR2 pos = D3DXVECTOR2( j * _tileWidth, (_mapWidth - i) * _tileHeight);
				D3DXVECTOR3 posCenter = D3DXVECTOR3(pos.x - _tileWidth / 2, pos.y - _tileWidth / 2 , 0);
				ManageSprite::createInstance()->draw(this->_IDImage, getRectRSInHM(IDTile), posCenter);
			}
		}
	}

	//ve GroundBGObj
	for (int i = 0; i < this->_listObjectInMap.size(); i++)
	{
		ObjectGame* object = this->_listObjectInMap.at(i);
		ManageSprite::createInstance()->drawObject(object);
	}
}

// luu 1 dong vao matran
void BackGround::addElement(std::vector<std::string> arr, int rowIndex)
{
	int IDTile;
	RECT* rectRS;
	for (int col = 0; col < arr.size(); ++col)
	{
		// add matrix
		IDTile = atoi(arr[col].c_str());
		this->_matrix[rowIndex][col] = IDTile;
		if (IDTile >= 600)
		{
			D3DXVECTOR2 pos = D3DXVECTOR2( col * _tileWidth, (_mapWidth - rowIndex) * _tileHeight);
			D3DXVECTOR2 posCenter = D3DXVECTOR2(pos.x + _tileWidth / 2, pos.y - _tileWidth / 2);

			// day la 1 doi tuong GroundBGObj
			//GroundBGObj* groundObj = GroundBGFac::getInstance()->createObj(IDTile);
			//groundObj->_pos = posCenter;
			//_listObjectInMap.push_back(groundObj);
		}
		else
		{
			// no khong phai la 1 doi tuong co va cham. Chi la doi tuong dung de ve background
			

			//insert rectRS and IDTIle into hashMap
			rectRS = getRectResouceByIDTile(IDTile);
			this->_listTileRectRS[IDTile] = rectRS;
		}

	}
}

//std::vector<string> BackGround::split(string s, char key)
//{
//	vector<string> arr;
//	string sTemp = "";
//	int index = 0;
//	while(index < s.length())
//	{
//		while(s[index] != key && index < s.length() && s[index] != ' ')
//		{
//			sTemp += s[index];
//			index++;
//		}
//		if(sTemp.size() > 0)
//			arr.push_back(sTemp);
//		index++;
//		sTemp.clear();
//	}
//	return arr;
//}

BackGround::~BackGround()
{
}
