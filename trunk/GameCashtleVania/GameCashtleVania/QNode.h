#ifndef __QNODE__
#define __QNODE__

#include "ObjectGame.h"

class QNode
{
public:
	//chua tat ca cac ID co trong Node - co the la ID Object or ID Tile
	std::vector<int> _listID;
	QNode *tl, *tr, *bl, *br;
	
	//vi tri top left
	int _x, _y, _width, _height;//Rect 
	RECT rect;

	//ID cua node
	int ID;
public:
	QNode(void);
	QNode(int _ID, int _x, int _y, int _widht, int _height);
	void addIDToList(int ID);
	bool isBound( RECT rect1, RECT rect2);
	//void getListObInScreen(std::vector<ObjectGame*> listObjectInGame, RECT Screen);
	void getListIDInScreen(std::vector<int> *listID, RECT Screen);
	~QNode();
};

#endif // !__QNODE__