#include "ManageGame.h"
#include "FileUtils.h"
#include "ManageTexture.h"
#include "ManageSprite.h"
#include "SimonFactory.h"
#include "Simon.h"

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
	ManageSprite::CreateInstance()->DrawObject( Simon::GetInstance() );
}

void ManageGame::Clear_Screen()
{
	_d3ddv->Clear(0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),1.0f,NULL);
}

void ManageGame::ProcessInput()
{
	Simon::GetInstance()->ProcessInput();
}

void ManageGame::GameUpdate(float DeltaTime)
{
	Simon::GetInstance()->Update(DeltaTime);
}

void ManageGame::GameInit()
{
	ManageSprite::CreateInstance()->Init_Sprite(this->SpriteHandle);
	ManageTexture::createInstance(this->_d3ddv);
	FileUtils::getInstance()->ReadFileImage();
	FileUtils::getInstance()->LoadCSV();
	SimonFactory::getInstance()->CreateObj();
}

void ManageGame::Delete_Memory_Game()
{

}