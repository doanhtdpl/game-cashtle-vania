#ifndef __QUAD__TREE__
#define __QUAD__TREE__

#include "QNode.h"
#include <hash_map>
//Node chua nhung node con va listID cua no

class QuadTree
{
public:
	//static QuadTree* _instance;
	QNode *root;//node goc
	std::hash_map< int, QNode*> listQNode;
	//file chua quadtree
	std::string fileQuadtree;
	//file chua object or tile
	std::string fileMap;
public:
	QuadTree();
	//static QuadTree* getInstance(); 

	//Load map ID va Rect va list tat ca cac node
	void loadMap();
	void loadListQNodeFromFile(std::string filePath);
	virtual void loadObjectFromFile(std::string filePath) = 0;

	//Dung lai quadtree tu list node
	void buildQuadTree(QNode*& Node);
	void searchIDNodeInList(QNode*& node, int ID);

	//lay tat ca ID co chua trong cac node co va cham voi Screen
	void getListIDInScreen(std::vector<int> *listID, RECT Screen);
	
	//ve tat ca object or tile trong quadtree
	virtual void draw(RECT Screen) = 0;

	void printQuadTree(QNode* Node);
	virtual void clearDataQuadtree();
	
	~QuadTree();
};

#endif // !__QUAD__TREE__