#ifndef __QUAD__TREE__BACKGROUND__
#define __QUAD__TREE__BACKGROUND__

#include "QuadTree.h"
#include "BackGround.h"

class QuadTreeBackground : public QuadTree
{
public:
	static QuadTreeBackground* getInstance();
	QuadTreeBackground();
	~QuadTreeBackground();

	BackGround mapBG;
	void loadObjectFromFile(std::string filePath);
	void draw(RECT Screen);
	void clearDataQuadtree();
protected:
private:
	static QuadTreeBackground* _instance;
};
#endif // !__QUAD__TREE__BACKGROUND__
