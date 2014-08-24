#include "ManageTexture.h"

ManageTexture* ManageTexture::_instance = NULL;

ManageTexture* ManageTexture::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new ManageTexture();
	}
	return _instance;
}

ManageTexture* ManageTexture::createInstance(LPDIRECT3DDEVICE9 _d3ddv) 
{
	if (_instance == NULL)
	{
		_instance = new ManageTexture(_d3ddv);
	}

	return _instance;
}

ManageTexture::ManageTexture()
{
	//this->list_Texture = new std::hash_map<int, Texture*>();
}

ManageTexture::ManageTexture(LPDIRECT3DDEVICE9 d3ddv)
{
	this->_d3ddv = d3ddv;
}

//doc tu file image lay key va filename---> texture
bool ManageTexture::createTextureByFileName(int key, std::string filename)
{
	Texture* texture = new Texture(this->_d3ddv);
	
	if (texture->load_Image(filename, color)) 
	{
		this->addTexture(key, texture);
		return true;
	}else
	{
		return false;
		//Show Message
		//MessageBox();
	}
}

//add texture vao hashmap theo key
void ManageTexture::addTexture(int key, Texture* texture)
{
	//this->list_Texture->insert(std::pair<int, Texture*>(key, texture));
	this->list_Texture[key] = texture;
}

//lay texture by key
Texture* ManageTexture::getTetureByKey(int key) 
{
	return this->list_Texture.find(key)->second;
}
