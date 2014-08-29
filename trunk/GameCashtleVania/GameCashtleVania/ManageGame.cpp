#include "ManageGame.h"
#include "FileUtils.h"
#include "ManageTexture.h"
#include "ManageSprite.h"
#include "SimonFactory.h"
#include "Simon.h"
#include "TagClassName.h"
#include "Itween.h"
#include "ManageAudio.h"
#include "GroundBGFac.h"
#include "utils.h"

int ManageGame::_score = 0;
bool ManageGame::isUseWatchItem = false;
bool ManageGame::isChangeScene = false;
bool ManageGame::isChangeTop = false;
bool ManageGame::isChangeDown = false;
InfoScene* ManageGame::_infoScene = NULL;
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
	this->_timeGame = 10;
	
	this->countLifeSimon = 5;

	this->currentState = TypeStateGame::MenuGame;
	this->stateGame = new MenuState();	
	this->delay = 0;
}

ManageGame::~ManageGame(void)
{
}

void ManageGame::gameDraw()
{

	switch (this->currentState)
	{
	case TypeStateGame::MenuGame:
		this->stateGame->draw();
		break;
	case TypeStateGame::IntroGame:
		this->stateGame->draw();
		break;
	case TypeStateGame::PlayGame:
		this->drawPlayGame();
		break;
	case TypeStateGame::NextMapGame:
		this->stateGame->draw();
		break;
	case TypeStateGame::EndGame:
		this->stateGame->draw();
		break;
	}
	
}

void ManageGame::drawPlayGame()
{
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
	}
	else
	{
		recentlyChangeScene = false;
	}

	this->_banner->draw();
}

void ManageGame::processInput()
{
	if (this->currentState == TypeStateGame::MenuGame)
	{
		Input::CreateInstance()->ProcessKeyboard();

		Input::CreateInstance()->Update();

		int key = Input::CreateInstance()->GetKeyDown();
		int key_up = Input::CreateInstance()->GetKeyUp();

		if (key == DIK_RETURN)
		{
			this->currentState = TypeStateGame::IntroGame;
			delete this->stateGame;
			this->stateGame = new IntroState();
			this->stateGame->init();
		}
	}
	
	
}

void ManageGame::gameUpdate(float deltaTime)
{
	switch (this->currentState)
	{
	case TypeStateGame::MenuGame:
		this->stateGame->update(deltaTime);
			break;
	case TypeStateGame::IntroGame:
		if (this->stateGame->isFinish() == true)
		{
			delay += deltaTime;
			if (delay > 2)
			{
				this->currentState = TypeStateGame::PlayGame;
				delete this->stateGame;
			}			
		}
		else
		{
			this->stateGame->update(deltaTime);
		}		
		break;
	case TypeStateGame::PlayGame:
		this->updatePlayGame(deltaTime);
		break;
	case TypeStateGame::NextMapGame:
		this->stateGame->update(deltaTime);
		break;
	case TypeStateGame::EndGame:
		this->stateGame->update(deltaTime);
		break;
	}
}

void ManageGame::updatePlayGame(float deltaTime)
{
	this->_timeGame += deltaTime;
	ManageSprite::createInstance()->update_Camera(Simon::getInstance()->_pos.x, deltaTime);
	screen = ManageSprite::createInstance()->_camera->getScreen();
	quadTreeObj->upDateQuadTree(screen);

	std::vector<ObjectGame*> arr;
	arr = quadTreeObj->getObjectInScreen(screen);
	std::vector<ObjectGame*>::iterator it = arr.begin();
	ObjectGame* obj = NULL;
	while (it != arr.end())
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
				enemy->pause = simon->_collisionItemRod;
			}

			enemy->update(deltaTime, arr);
		}
		else
		{
			if (obj->className() == TagClassName::getInstance()->tagGroundObject)
			{
				obj->update(deltaTime, arr);
			}
			else
			{
				obj->update(deltaTime);
			}
		}
	}

	//khong co trang thai change scene
	if (!isChangeScene)
	{
		simon->update(deltaTime, arr);
	}
	else
	{
		if (_infoScene->level == 1 && !simon->_Left)
		{
			changeScene(deltaTime);
		}
		else
		{
			simon->update(deltaTime, arr);
		}
	}

	if (simon->_simonDie)
	{
		simon->_simonDie = false;
		this->restartGame();
		simon->reset();
	}

	if (isChangeDown)
	{
		this->changeSceneDown();
		isChangeDown = false;
	}

	if (isChangeTop)
	{
		this->changeSceneTop();
		isChangeTop = false;
	}
	//delete obj;
	arr.clear();

	this->_banner->update(deltaTime);
}

void ManageGame::restartGame()
{
	this->countLifeSimon --;
	if (this->countLifeSimon > 0)
	{
		if (this->_infoScene->iD_Scene + this->_infoScene->level * 10 == 14)
		{
			nextScene(-1);
		}else
		{
			nextScene(0);
		}
	}
	else
	{
		this->loseGame();
	}
	
}

void ManageGame::changeScene(float deltaTime)
{
	int Id_scene = this->level * 10 + this->scene;
	int posXSimonTarget;
	int posXCamera;
	D3DXVECTOR2 posGate;
	switch (Id_scene)
	{
	case 11:
		//level 1 scene 1
		simon->_moveMent = SimonMove::Moves;
		simon->animated(deltaTime);
		if(simon->autoMove(D3DXVECTOR2(simon->_pos.x + 300, simon->_pos.y), deltaTime))
		{
			acting = false;
			isChangeScene = false;
			nextScene(1);
		}
		break;
	case 12:
		//level 1 scene 2
		if (changeSceneWithGate(deltaTime))
		{
			isChangeScene = false;
			nextScene(1);
		}
		break;
	case 13:
		//level 1 scene 3
		if (changeSceneWithGate(deltaTime))
		{
			isChangeScene = false;
			nextScene(2);
		}
		break;
	default:
		break;
	}
	//simon->animated(deltaTime);
}

bool ManageGame::changeSceneWithGate(float deltaTime)
{
	int Id_scene = this->level * 10 + this->scene;
	int posXSimonTarget;
	int posXCamera;

	if (!openGate)
	{
		if (ManageSprite::createInstance()->_camera->move(simon->_Vx_default, simon->_pos.x, deltaTime))
		{
			openGate = true;
			int ID_Gate = 650 + level;
			gate = (Gate*)GroundBGFac::getInstance()->createObj(ID_Gate);
			gate->_pos.x = simon->getRect().right + 32;
			gate->_pos.y = simon->getRect().bottom + gate->_height / 2;
			gate->finish = false;
			this->finish_simon_automove = false;
			//quadTreeObj->addObjectToQuadTree(gate);
		}
	}else
	{
		gate->update(deltaTime);
		if (gate->finish)
		{
			if (!finish_simon_automove)
			{
				simon->_moveMent = SimonMove::Moves;
				posXSimonTarget = this->_infoScene->width + 128;
				this->finish_simon_automove = simon->autoMove(D3DXVECTOR2(posXSimonTarget, simon->_pos.y), deltaTime);
			}else
			{
				simon->_moveMent = SimonMove::Idle;
				posXCamera = this->_infoScene->width + Screen_Width / 2;
				if (ManageSprite::createInstance()->_camera->move(simon->_Vx_default, posXCamera, deltaTime))
				{
					this->finish_simon_automove = false;
					this->openGate = false;
					
					acting = false;
					return true;
				}
			}
			simon->animated(deltaTime);
		}
	}

	return false;
}

void ManageGame::changeSceneDown()
{
	if (this->_infoScene->level == 1)
	{
		//lay vi tri simon truoc khi chuyen scene
		D3DXVECTOR2 posSimonDown = D3DXVECTOR2(simon->_pos.x, 348);
		nextScene(1);	
		//cap nhap lai vi tri simon
		simon->_pos = posSimonDown;
		simon->_changingDown = false;
	}else
	{
		//lay vi tri simon truoc khi chuyen scene
		D3DXVECTOR2 posSimonDown = D3DXVECTOR2(simon->_pos.x, 348);
		nextScene(-1);	
		//cap nhap lai vi tri simon
		simon->_pos = posSimonDown;
		simon->_changingDown = false;
	}
}

void ManageGame::changeSceneTop()
{
	if (level == 1)
	{
		D3DXVECTOR2 posSimonTop = D3DXVECTOR2(simon->_pos.x, 45);
		nextScene(-1);
		simon->_pos = posSimonTop;
		simon->_changingTop = false;
	}else
	{
		if (level == 2)
		{
			D3DXVECTOR2 posSimonTop = D3DXVECTOR2(simon->_pos.x, 45);
			//posSimonTop.x += MapLoader::getInstance()->getInfoSceneByKey(level * 10 + scene + 1)->width - this->_infoScene->width;
			posSimonTop =  MapLoader::getInstance()->getInfoSceneByKey(level * 10 + scene + 1)->_posSimon;
			nextScene(1);
			simon->_pos = posSimonTop;
			simon->_changingTop = false;
		}
	}
	
}

void ManageGame::nextScene(int increaseScene)
{
	this->_infoScene = MapLoader::getInstance()->getInfoSceneByKey(level * 10 + scene);
	if (this->_infoScene->finalScene)
	{
		nextLevel();
	}else
	{
		this->scene += increaseScene;
		this->_infoScene = MapLoader::getInstance()->getInfoSceneByKey(level * 10 + scene);

		//dua thong tin file cho quadtree
		quadTreeBG->clearDataQuadtree();
		quadTreeObj->clearDataQuadtree();

		quadTreeBG->fileMap = this->_infoScene->bGPath;
		quadTreeBG->fileQuadtree = this->_infoScene->bGQuadTree;
		quadTreeBG->loadMap();

		quadTreeObj->fileMap = this->_infoScene->mapPath;
		quadTreeObj->fileQuadtree = this->_infoScene->mQuadTree;
		quadTreeObj->loadMap();

		//xet lai bound cho camera
		ManageSprite::createInstance()->_camera->setBound(this->_infoScene->getBound());
		simon->_boundScene = this->_infoScene->getBound();

		quadTreeObj->upDateQuadTree(this->screen);
		simon->_pos = this->_infoScene->_posSimon;
		//simon->reset();
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
	scene = 1;
	ManageAudio::getInstance()->playSound(TypeAudio::Stage_01_Vampire_Killer);

	this->_infoScene = MapLoader::getInstance()->getInfoSceneByKey(level * 10 + scene);
	//dua thong tin file cho quadtree

	quadTreeBG->fileMap = this->_infoScene->bGPath;
	quadTreeBG->fileQuadtree = this->_infoScene->bGQuadTree;
	quadTreeBG->loadMap();

	quadTreeObj->fileMap = this->_infoScene->mapPath;
	quadTreeObj->fileQuadtree = this->_infoScene->mQuadTree;
	quadTreeObj->loadMap();

	//add simon vao quad tre
	
	//quadTreeObj->addObjectToQuadTree(simon);

	ManageSprite::createInstance()->_camera->setBound(this->_infoScene->getBound());
	screen = ManageSprite::createInstance()->_camera->getScreen();
	simon->_boundScene = this->_infoScene->getBound();
	simon->_pos = this->_infoScene->_posSimon;

	quadTreeObj->upDateQuadTree(screen);

	// banner
	this->_banner->init();

	//state game
	this->stateGame->init();
}

bool ManageGame::pauseGame(float deltaTime)
{
	this->_timePause -= deltaTime;
	if (this->_timePause <= 0)
	{
		return true;
	}else
	{
		return false;
	}
}

void ManageGame::delete_Memory_Game()
{

}

void ManageGame::clear_Screen()
{
	_d3ddv->Clear(0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),1.0f,NULL);
}