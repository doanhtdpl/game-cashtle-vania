#ifndef __BANNER__H__
#define __BANNER__H__

#include "StaticObject.h"
#include "IAnimatedSprite.h"
#include "Weapon.h"
#include <d3dx9.h>
#include "Texture.h"
enum class TYPEBANNER
{
	FullBanner = 3000,
	HeathEnemy = 3001,
	HeathPlayer = 3002
};

class BANNER 
{
public:
    // basic info of banner 
	/*int _hpSimon;
	int _countHeartSimon;
	int _hpEnemy;
	int _time;
	int _score;
	int _scene;
	int _numberSimon;
	TypeWeapon _typeWeapon;*/

	// position of item
	//D3DXVECTOR3 posScore;
	//D3DXVECTOR3 posTime;
	//D3DXVECTOR3 posScene;
	//D3DXVECTOR3 posHpSimon;
	//D3DXVECTOR3 posHpEnemy;
	//D3DXVECTOR3 posCurrentWeapon;
	//D3DXVECTOR3 posCountHeart;
	//D3DXVECTOR3 posNumberSimon;	
	//D3DXVECTOR3 posTypeWeapon;
	//D3DXVECTOR3 posNumber;
	D3DXVECTOR3 posBGBanner;

	//texture of item
	Texture *textureBGBanner;
	//Texture* textureWeapon;
	//Texture* textureHpEnemy;
	//Texture* textureHpPlayer;

	// method of banner
	BANNER();
	BANNER(std::vector<std::string> arr);
	void update(float deltaTime);
	void draw();
	~BANNER();
private:
	
};


#endif // !__BANNER__H__
