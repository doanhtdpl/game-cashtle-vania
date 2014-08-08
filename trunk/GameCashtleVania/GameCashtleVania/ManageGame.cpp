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
	_mapBG->drawBackGround();

	ManageSprite::createInstance()->drawObject( Simon::getInstance() );
	if (Simon::getInstance()->ironRod->_isALive)
	{
		ManageSprite::createInstance()->drawObject( Simon::getInstance()->ironRod );
	}

	std::hash_map<int, ObjectGame*>::iterator it = _map->listObjectInMap.begin();
	while (it != _map->listObjectInMap.end())
	{
		//draw
		ObjectGame* obj = it->second;
		if (obj->className() != TagClassName::getInstance()->tagHideObject)
		{
			ManageSprite::createInstance()->drawObject(obj);
		}
		
		++it;
	}
}


void ManageGame::processInput()
{
	Simon::getInstance()->processInput();
}

void ManageGame::gameUpdate(float deltaTime)
{
	ManageSprite::createInstance()->update_Camera(Simon::getInstance()->_pos.x);
	
	std::vector<ObjectGame*> arr;
	std::hash_map<int, ObjectGame*>::iterator it = _map->listObjectInMap.begin();
	while (it != _map->listObjectInMap.end())
	{
		//draw
		ObjectGame* obj = it->second;
		arr.push_back(obj);
		if (obj->className() != TagClassName::getInstance()->tagHideObject)
		{
			obj->update(deltaTime);
		}
		++it;
	}

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
	
	_mapBG = new BackGround();
	_map = new Map();
	level = 1;
	scene = 1;
	InfoScene* infoScene = MapLoader::getInstance()->getInfoSceneByKey(level * 10 + scene);
	_mapBG->readFromFile(infoScene->bGPath);
	_map->readMapFromFile(infoScene->mapPath);
}

void ManageGame::delete_Memory_Game()
{

}

void ManageGame::clear_Screen()
{
	_d3ddv->Clear(0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),1.0f,NULL);
}