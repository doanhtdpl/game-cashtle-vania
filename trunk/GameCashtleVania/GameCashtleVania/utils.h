#pragma once
#ifndef FrameWork


#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <dsound.h>
	

#include <Windows.h>
#include <time.h>
#include <iostream>
#include <list>
#include <hash_map>
#include <iterator>
#include <vector>
#include <fstream>
#include <string>

//#include "Input.h"
//#include "Sprite.h"
//#include "Surface.h"
//#include "Texture.h"

using namespace std;



#define ClassName "Mario Ozawa"
#define Screen_Width 800
#define Screen_Height 600
#define Frame_Rate 30
#define KEYBOARD_BUFFER_SIZE 256
#define Mario_Vx 0.2
#define Mario_Vy 0.5
#define Mario_Jum_Height 200
#define Mario_Height 90
#define Mario_Width 47
#define Land_Height 100
#define Land_Width 50

#define Kind_LandLeft 11
#define Kind_LandMid 12
#define Kind_LandRight 13
#define Kind_Land2Left 14
#define Kind_Land2Mid 15
#define Kind_Land2Right 16
#define Kind_Block 17
#define Kind_Brick 20
#define Kind_BrickContainsCoin 21
#define Kind_PieceBrickLeft 22
#define Kind_PieceBrickRight 23
#define Kind_Stone 30
#define Kind_StoneContainsCoin 31
#define Kind_StoneContainsRedMushroom 32
#define Kind_StoneContainsGreenMushroom 33
#define Kind_StoneContainsFlower 34
#define Kind_StoneContainsStar 35
#define Kind_SewerHorizontalLeft 40
#define Kind_SewerHorizontalRight 41
#define Kind_SewerVertical1 42
#define Kind_SewerVertical2 43
#define Kind_SewerVertical3 44
#define Kind_SewerVerticalCreep 45
#define Kind_FlowerKillPlayer 50
#define Kind_Coin 60
#define Kind_CoinFly 61
#define Kind_InvisibleObject 70

#define Kind_Draw_Cloud 80
#define Kind_Draw_Finish 81
#define Kind_Draw_Grass 82
#define Kind_Draw_Fence 83
#define Kind_Draw_Mountain 84
#define Kind_Draw_Tree1 85
#define Kind_Draw_Tree2 86

#define Kind_ToxicMushroom 100
#define Kind_GreenTortoise 110
#define Kind_RedTortoise 111
#define Kind_KingTortoise 112
#define Kind_ShellGreen 113
#define Kind_ShellRed 114
#define Kind_CrossBarVertical 120
#define Kind_CrossBarHorizontal 121
#define Kind_Item_RedMushroom 130
#define Kind_Item_GreenMushroom 131
#define Kind_Item_Flower 132
#define Kind_Item_Star 133
#define Kind_BulletOfMario 140
#define Kind_BulletOfTortoise 141

#define Kind_MarioSmall 151
#define Kind_MarioBig 152
#define Kind_MarioGun 153
#define Kind_MarioSmallSuperman 154
#define Kind_MarioBigSuperman 155
#define Kind_MarioGunSuperman 156

enum Posture_Moves
{
	None,//khong gi ca
	Run,//dang chay
	Stand,//dung yen
	Sit,//dang ngoi
	Jum,//dang nhay
	Free//dang roi tu do
};

enum Type_State1
{
	Menu_State = 1,
	Play_State = 2,
	Pause_State = 3,
	Help_State = 4,
	Save_State = 5,
	Load_State = 6
};

enum Choice_Menu
{
	Start_Game = 1,
	Load_Game = 2,
	Game_Setting = 3,
	Help_Game = 4,
	Exit_Game = 5,
	Play_Game = 6
};

enum Choice_Setting
{
	Music_BG = 1,
	Sound = 2
};

enum World_Map
{
	Level1 = 1,
	Level2 = 2,
	Level3 = 3,
	Creep_Sewer1 = 4,
	Creep_Sewer2 = 5,
	Creep_Sewer3 = 6
};
#endif // !FrameWork
