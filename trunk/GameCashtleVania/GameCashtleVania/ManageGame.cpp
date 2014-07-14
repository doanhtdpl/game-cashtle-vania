#include "ManageGame.h"
#include "FileUtils.h"
#include "ManageTexture.h"
#include "ManageSprite.h"
#include "SimonFactory.h"

int ManageGame::_Word_Map = 1;
int ManageGame::_count_LifeMario = 4;
int ManageGame::_score = 0;

ManageGame::ManageGame(void)
{
	//ListObjectOnScenes = new list<ObjectGame*>();
	
}

ManageGame::~ManageGame(void)
{
}


void ManageGame::GameDraw()
{
	ManageSprite::CreateInstance()->DrawObject(simon);
}

void ManageGame::Clear_Screen()
{

}

void ManageGame::ProcessInput()
{

}

void ManageGame::GameUpdate(DWORD DeltaTime)
{

}

void ManageGame::GameInit()
{
	ManageSprite::CreateInstance()->Init_Sprite(this->SpriteHandle);
	ManageTexture::createInstance(this->_d3ddv);
	FileUtils::getInstance()->ReadFileImage();
	FileUtils::getInstance()->LoadCSV();
	simon = SimonFactory::getInstance()->CreateObj();
}

void ManageGame::Delete_Memory_Game()
{

}