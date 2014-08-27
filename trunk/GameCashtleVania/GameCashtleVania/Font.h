#ifndef __FONT_H_
#define __FONT_H_

#include "utils.h"
#include "IAnimatedSprite.h"
#include "Texture.h"

class Font : public IAnimatedSprite
{
public:
	int _width;
	int _height;
	RECT* _rectRS;
	Texture* image_font;
public:
	Font(void);
	~Font(void);
	void drawFont(char* s, float x, float y);
	void drawFont(int number, float x, float y);
};

#endif // !__FONT_H_



