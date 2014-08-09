#include "QuadTreeBackground.h"

QuadTreeBackground* QuadTreeBackground::_instance = NULL;

QuadTreeBackground* QuadTreeBackground::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new QuadTreeBackground();
	}

	return _instance;
}

QuadTreeBackground::QuadTreeBackground()
{

}

QuadTreeBackground::~QuadTreeBackground()
{

}

void QuadTreeBackground::loadObjectFromFile(std::string filePath)
{
	mapBG.readMapFromFile(filePath);
}

void QuadTreeBackground::draw(RECT screen)
{
	//lay ID object trong man hinh
	std::vector<int>* listID = new std::vector<int>();
	getListIDInScreen(listID, screen);

	//duyet list ID
	std::vector<int>::iterator it;
	it = listID->begin();
	int ID;
	while (it != listID->end())
	{
		//ID trong list object 
		ID = *it++;
		
		//draw tile voi ID
		mapBG.drawTileByID(ID);
	}
}