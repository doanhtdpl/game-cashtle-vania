#include "ManageGame.h"
#include "FileUtils.h"
#include "ManageTexture.h"
#include "ManageSprite.h"
#include "SimonFactory.h"
#include "Simon.h"
#include "MapLoader.h"
#include "TagClassName.h"

int ManageGame::_count_LifeMario = 4;
int ManageGame::_score = 0;

ManageGame::ManageGame(void)
{
	//ListObjectOnScenes = new list<ObjectGame*>();
}

ManageGame::~ManageGame(void)
{
}

void ManageGame::gameDraw()
{
	//_mapBG->drawBackGround();


	quadTreeBG->draw(screen);
	quadTreeObj->draw(screen);

	ManageSprite::createInstance()->drawObject( Simon::getInstance() );
	if (Simon::getInstance()->ironRod->_isALive)
	{
		ManageSprite::createInstance()->drawObject( Simon::getInstance()->ironRod );
	}
	//std::hash_map<int, ObjectGame*>::iterator it = _map->listObjectInMap.begin();
	//while (it != _map->listObjectInMap.end())
	//{
	//	//draw
	//	ObjectGame* obj = it->second;
	//	if (obj->className() != TagClassName::getInstance()->tagHideObject)
	//	{
	//		ManageSprite::createInstance()->drawObject(obj);
	//	}
	//	
	//	++it;
	//}
}


void ManageGame::processInput()
{
	Simon::getInstance()->processInput();
}

void ManageGame::gameUpdate(float deltaTime)
{
	ManageSprite::createInstance()->update_Camera(Simon::getInstance()->_pos.x);
	screen = ManageSprite::createInstance()->_camera->getScreen();

	std::vector<ObjectGame*> arr;
	arr = quadTreeObj->getObjectInScreen(screen);
	std::vector<ObjectGame*>::iterator it = arr.begin();
	ObjectGame* obj;
	while(it != arr.end())
	{
		obj = *it++;
		obj->update(deltaTime);
	}
	//std::hash_map<int, ObjectGame*>::iterator it;
	//while (it != _map->listObjectInMap.end())
	//{
	//	//draw
	//	ObjectGame* obj = it->second;
	//	arr.push_back(obj);
	//	if (obj->className() != TagClassName::getInstance()->tagHideObject)
	//	{
	//		obj->update(deltaTime);
	//	}
	//	++it;
	//}

	Simon::getInstance()->update(deltaTime, arr);
	//Simon::getInstance()->collision((StaticObject*)brick, normalX, normalY, DeltaTime);
}

void ManageGame::gameInit()
{
	MapLoader::getInstance()->readInfoSceneFromFile();
	ManageSprite::createInstance()->init_Sprite(this->SpriteHandle);
	ManageTexture::createInstance(this->_d3ddv);
	
	FileUtils::getInstance()->readFileImage();
	FileUtils::getInstance()->loadCSV();
	
	//tao Simon
	SimonFactory::getInstance()->createObj();
	
	quadTreeBG = QuadTreeBackground::getInstance();
	quadTreeObj = QuadTreeObject::getInstance();
	
	level = 1;
	scene = 1;
	InfoScene* infoScene = MapLoader::getInstance()->getInfoSceneByKey(level * 10 + scene);
	//dua thong tin file cho quadtree

	quadTreeBG->fileMap = infoScene->bGPath;
	quadTreeBG->fileQuadtree = infoScene->bGQuadTree;
	quadTreeBG->loadMap();

	quadTreeObj->fileMap = infoScene->mapPath;
	quadTreeObj->fileQuadtree = infoScene->mQuadTree;
	quadTreeObj->loadMap();


	screen = ManageSprite::createInstance()->_camera->getScreen();
}

void ManageGame::delete_Memory_Game()
{

}

void ManageGame::clear_Screen()
{
	_d3ddv->Clear(0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),1.0f,NULL);
}