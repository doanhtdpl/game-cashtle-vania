#include "ManageGame.h"
#include "FileUtils.h"
#include "ManageTexture.h"
#include "ManageSprite.h"
#include "SimonFactory.h"
#include "Simon.h"
#include "MapLoader.h"
#include "TagClassName.h"
#include "Itween.h"

int ManageGame::_count_LifeMario = 4;
int ManageGame::_score = 0;
bool ManageGame::isChangeScene = false;

ManageGame* ManageGame::_instance = NULL;

ManageGame* ManageGame::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new ManageGame();
	}

	return _instance;
}

ManageGame::ManageGame()
{
	//ListObjectOnScenes = new list<ObjectGame*>();
	//isChangeScene = false;
	acting = false;
}

ManageGame::~ManageGame(void)
{
}

void ManageGame::gameDraw()
{
	//_mapBG->drawBackGround();


	quadTreeBG->draw(screen);
	quadTreeObj->draw(screen);

	ManageSprite::createInstance()->drawObject(simon);
	if (Simon::getInstance()->ironRod->_isALive)
	{
		ManageSprite::createInstance()->drawObject( simon->ironRod );
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
	//Simon::getInstance()->processInput();
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

	//khong co trang thai change scene
	if (!isChangeScene)
	{
		simon->update(deltaTime, arr);
	}else
	{
		changeScene(deltaTime);
	}
	
}

void ManageGame::changeScene(float deltaTime)
{
	
	if (!acting)
	{
		//chua dien ra hanh dong
		D3DXVECTOR2 posFrom = simon->_pos;
		D3DXVECTOR2 posTo = D3DXVECTOR2(simon->_pos.x + 300, simon->_pos.y);
		D3DXVECTOR2 speed = D3DXVECTOR2(simon->_Vx_default, 0);

		Itween::getInstance()->posFrom = posFrom;
		Itween::getInstance()->posTo = posTo;
		Itween::getInstance()->speed = speed;
		Itween::getInstance()->timeDelay = 2.0;
		Itween::getInstance()->wasActing = false;
		acting = true;
	}else
	{
		simon->_moveMent = SimonMove::Moves;
		simon->animated(deltaTime);
		if (Itween::getInstance()->MoveTo(simon, deltaTime))
		{
			acting = false;
			isChangeScene = false;
			nextScene();
		}
	}
	
	

}

void ManageGame::nextScene()
{
	InfoScene* infoScene = MapLoader::getInstance()->getInfoSceneByKey(level * 10 + scene);
	if (infoScene->finalScene)
	{
		nextLevel();
	}else
	{
		this->scene++;
		infoScene = MapLoader::getInstance()->getInfoSceneByKey(level * 10 + scene);

		//dua thong tin file cho quadtree

		quadTreeBG->fileMap = infoScene->bGPath;
		quadTreeBG->fileQuadtree = infoScene->bGQuadTree;
		quadTreeBG->loadMap();

		quadTreeObj->fileMap = infoScene->mapPath;
		quadTreeObj->fileQuadtree = infoScene->mQuadTree;
		quadTreeObj->loadMap();

		simon->_pos = D3DXVECTOR2(60, 64);
	}
}

void ManageGame::nextLevel()
{

}

void ManageGame::winGame()
{

}

void ManageGame::loseGame()
{

}

void ManageGame::gameInit()
{
	MapLoader::getInstance()->readInfoSceneFromFile();
	ManageSprite::createInstance()->init_Sprite(this->SpriteHandle);
	ManageTexture::createInstance(this->_d3ddv);
	
	FileUtils::getInstance()->readFileImage();
	FileUtils::getInstance()->loadCSV();
	
	//tao Simon
	simon = SimonFactory::getInstance()->createObj();
	
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