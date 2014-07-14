#ifndef __MANAGE_TEXTURE_H__
#define __MANAGE_TEXTURE_H__

#include <hash_map>
#include "Texture.h"
#include <string>
#define color D3DCOLOR_XRGB(255, 0, 255)

class ManageTexture
{
public:
	static ManageTexture* createInstance(LPDIRECT3DDEVICE9 _d3ddv);
	static ManageTexture* getInstance();
	bool createTextureByFileName(int key, std::string filename);
	void addTexture(int key, Texture* texture);
	Texture* getTetureByKey(int key);
	ManageTexture();
	ManageTexture(LPDIRECT3DDEVICE9 _d3ddv);
protected:
private:
	static ManageTexture* _instance;
	std::hash_map<int, Texture*> list_Texture;
	LPDIRECT3DDEVICE9 _d3ddv;
};

#endif // !__MANAGE_TEXTURE_H__
