#ifndef __MENU_ANIMATION_
#define __MENU_ANIMATION_

#include "IAnimatedSprite.h"
#include <d3dx9.h>
#include "Texture.h"

class MenuAnimation : public IAnimatedSprite
{
public:	
	MenuAnimation ();
	~MenuAnimation ();
	void update(float deltaTime);
	void draw();
	void init();

private:
	D3DXVECTOR3 _pos;
	Texture* _texture;
	RECT* _rect;
	int _width;
	int _height;
};


#endif // !__MENU_ANIMATION_
