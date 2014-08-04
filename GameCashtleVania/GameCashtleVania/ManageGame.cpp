#include "ManageGame.h"
#include "FileUtils.h"
#include "ManageTexture.h"
#include "ManageSprite.h"
#include "SimonFactory.h"
#include "Simon.h"
#include "MapLoader.h"

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
	mapBG->drawBackGround();

	ManageSprite::createInstance()->drawObject( Simon::getInstance() );
	if (Simon::getInstance()->ironRod->_isALive)
	{
		ManageSprite::createInstance()->drawObject( Simon::getInstance()->ironRod );
	}
	
	//if (IronRod::getInstance()->_isALive)
	//{
	//	ManageSprite::createInstance()->drawObject( IronRod::getInstance() );
	//}
	//ManageSprite::createInstance()->drawObject(brick);
}


void ManageGame::processInput()
{
	Simon::getInstance()->processInput();
}

void ManageGame::gameUpdate(float deltaTime)
{
	ManageSprite::createInstance()->update_Camera(Simon::getInstance()->_pos.x);
	Simon::getInstance()->update(deltaTime, mapBG->_listObjectInMap);
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
	
	mapBG = new BackGround();
	//mapBG->readFromFile("..\\Resource\\MapBackGround\\mapBG.txt");
	level = 1;
	scene = 1;
	InfoScene* infoScene = MapLoader::getInstance()->getInfoSceneByKey(level * 10 + scene);
	mapBG->readFromFile(infoScene->bGPath);
}

void ManageGame::delete_Memory_Game()
{

}

void ManageGame::clear_Screen()
{
	_d3ddv->Clear(0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),1.0f,NULL);
}