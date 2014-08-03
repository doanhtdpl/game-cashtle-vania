#ifndef __UTILS___
#define __UTILS___

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define EslapseTimeSwitchFrame 0.09

#define ClassName "Cashtle Vania"
#define Screen_Width 800
#define Screen_Height 600
#define Frame_Rate 60
#define KEYBOARD_BUFFER_SIZE 256

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
//
//enum World_Map
//{
//	Level1 = 1,
//	Level2 = 2,
//	Level3 = 3,
//	Creep_Sewer1 = 4,
//	Creep_Sewer2 = 5,
//	Creep_Sewer3 = 6
//};

enum Posture_Moves
{
	//None,//khong gi ca
	//Run,//dang chay
	//Stand,//dung yen
	//Sit,//dang ngoi
	//Jum,//dang nhay
	//Free//dang roi tu do
};

#endif // !__UTILS___