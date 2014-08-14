#ifndef __QUAD__TREE__OBJECT__
#define __QUAD__TREE__OBJECT__

#include "QuadTree.h"
#include "Map.h"

class QuadTreeObject : public QuadTree
{
public:
	static QuadTreeObject* getInstance();
	QuadTreeObject();
	~QuadTreeObject();

	Map mapObject;
	std::vector<ObjectGame*> getObjectInScreen(RECT screen);
	void loadObjectFromFile(std::string filePath);

	void upDateQuadTree();
	void addObjectToQuadTree(ObjectGame* object);
	void draw(RECT Screen);
	void clearDataQuadtree();
protected:
	void upDateQNode(QNode* Node);
	void addObjectToNode(QNode* Node, ObjectGame* object, int IDObjInList);
private:
	static QuadTreeObject* _instance;

};

#endif // !__QUAD__TREE__OBJECT__
