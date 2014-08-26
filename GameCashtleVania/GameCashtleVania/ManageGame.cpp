#include "ManageGame.h"
#include "FileUtils.h"
#include "ManageTexture.h"
#include "ManageSprite.h"
#include "SimonFactory.h"
#include "Simon.h"
#include "MapLoader.h"
#include "TagClassName.h"
#include "Itween.h"
#include "ManageAudio.h"
#include "GroundBGFac.h"

int ManageGame::_score = 0;
bool ManageGame::isUseWatchItem = false;
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
	this->recentlyChangeScene = false;
	this->openGate = false;
	this->isUseWatchItem = false;
	this->maxNumberSecondEffect = 3;
	this->currentNumberSecondEffect = 0;

	this->_banner = new BANNER();
}

ManageGame::~ManageGame(void)
{
}

void ManageGame::gameDraw()
{
	this->_banner->draw();
	//chuyen scene vua xong thi khong ve
	if (!recentlyChangeScene)
	{
		quadTreeBG->draw(screen);
		quadTreeObj->draw(screen);

		if (openGate)
		{
			ManageSprite::createInstance()->drawObject(gate);
		}

		simon->draw();
	}else
	{
		recentlyChangeScene = false;
	}
}

void ManageGame::processInput()
{
	//Simon::getInstance()->processInput();
}

void ManageGame::gameUpdate(float deltaTime)
{
	this->_banner->update(deltaTime);
	ManageSprite::createInstance()->update_Camera(Simon::getInstance()->_pos.x, deltaTime);
	screen = ManageSprite::createInstance()->_camera->getScreen();
	quadTreeObj->upDateQuadTree(screen);

	std::vector<ObjectGame*> arr;
	arr = quadTreeObj->getObjectInScreen(screen);
	std::vector<ObjectGame*>::iterator it = arr.begin();
	ObjectGame* obj = NULL;
	while(it != arr.end())
	{
		obj = *it++;
		if (obj->className() == TagClassName::getInstance()->tagItem)
		{
			DynamicObject* dynamicObject = (DynamicObject*)obj;
			obj->update(deltaTime, arr);
		}
		else if (obj->className() == TagClassName::getInstance()->tagEnemy)
		{
			Enemy* enemy = (Enemy*)obj;
			//kiem tra simon co su dung item watch
			if (this->isUseWatchItem == true)
			{
				this->currentNumberSecondEffect += deltaTime;
				if (currentNumberSecondEffect >= this->maxNumberSecondEffect)
				{
					currentNumberSecondEffect = 0;
					isUseWatchItem = false;
				}
				enemy->pause = true;
			}						
			else
			{
				enemy->pause = false;
			}

			enemy->update(deltaTime, arr);							
		}
		else
		{
			obj->update(deltaTime);
		}
	}

	//khong co trang thai change scene
	if (!isChangeScene)
	{
		simon->update(deltaTime, arr);
	}else
	{
		changeScene(deltaTime);
	}

	//delete obj;
	arr.clear();
	
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
		if (!openGate)
		{
			if (ManageSprite::createInstance()->_camera->move(simon->_Vx_default, simon->_pos.x, deltaTime))
			{
				openGate = true;
				int ID_Gate = 650 + level;
				gate = (Gate*)GroundBGFac::getInstance()->createObj(ID_Gate);
				gate->_pos.x = simon->getRect().right + gate->_width / 2;
				gate->_pos.y = simon->getRect().bottom + gate->_height / 2;
				//quadTreeObj->addObjectToQuadTree(gate);
			}
		}else
		{
			gate->update(deltaTime);
			if (gate->finish)
			{
				simon->_moveMent = SimonMove::Moves;
				simon->animated(deltaTime);
				if (simon->autoMove(gate->_pos.x + 100, deltaTime))
				{
					if (ManageSprite::createInstance()->_camera->move(simon->_Vx_default, simon->_pos.x, deltaTime))
					{
						simon->_moveMent = SimonMove::Idle;
						acting = false;
						isChangeScene = false;
						nextScene();
					}
				}
				/*if (Itween::getInstance()->MoveTo(simon, deltaTime))
				{
					
				}*/
			}
			
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
		quadTreeBG->clearDataQuadtree();
		quadTreeObj->clearDataQuadtree();

		quadTreeBG->fileMap = infoScene->bGPath;
		quadTreeBG->fileQuadtree = infoScene->bGQuadTree;
		quadTreeBG->loadMap();

		quadTreeObj->fileMap = infoScene->mapPath;
		quadTreeObj->fileQuadtree = infoScene->mQuadTree;
		quadTreeObj->loadMap();

		//xet lai bound cho camera
		ManageSprite::createInstance()->_camera->setBound(infoScene->getBound());
		simon->_boundScene = infoScene->getBound();

		quadTreeObj->upDateQuadTree(this->screen);
		simon->_pos = infoScene->_posSimon;
		//quadTreeObj->addObjectToQuadTree(simon);
		ManageSprite::createInstance()->_camera->stopScrollScreen = false;
		this->recentlyChangeScene = true;
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

	if (!ManageAudio::getInstance()->init_DirectSound(this->_hWnd))
	{
		return;
	}
	
	FileUtils::getInstance()->loadCSV();
	
	//tao Simon
	simon = SimonFactory::getInstance()->createObj();
	
	quadTreeBG = QuadTreeBackground::getInstance();
	quadTreeObj = QuadTreeObject::getInstance();
	
	level = 1;
	scene = 2;
	ManageAudio::getInstance()->playSound(TypeAudio::Stage_01_Vampire_Killer);

	InfoScene* infoScene = MapLoader::getInstance()->getInfoSceneByKey(level * 10 + scene);
	//dua thong tin file cho quadtree

	quadTreeBG->fileMap = infoScene->bGPath;
	quadTreeBG->fileQuadtree = infoScene->bGQuadTree;
	quadTreeBG->loadMap();

	quadTreeObj->fileMap = infoScene->mapPath;
	quadTreeObj->fileQuadtree = infoScene->mQuadTree;
	quadTreeObj->loadMap();

	//add simon vao quad tre
	
	//quadTreeObj->addObjectToQuadTree(simon);

	ManageSprite::createInstance()->_camera->setBound(infoScene->getBound());
	screen = ManageSprite::createInstance()->_camera->getScreen();
	simon->_boundScene = infoScene->getBound();
	simon->_pos = infoScene->_posSimon;

	quadTreeObj->upDateQuadTree(screen);
}

void ManageGame::delete_Memory_Game()
{

}

void ManageGame::clear_Screen()
{
	_d3ddv->Clear(0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),1.0f,NULL);
}