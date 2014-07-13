#ifndef __OBJECT_GAME__H__
#define __OBJECT_GAME__H__

#include <d3dx9.h>
#include <list>
class ObjectGame
{
public:
	int _kind;
	int _ID;//each object has a ID to identified with other object
	RECT _rect;//rect used to check collision
	D3DXVECTOR3 _pos;//position of object
	bool _isALive;//life or die??
	int _height;//height of object and uses to draw.
	int _width;

	bool _isAnimatedSprite;//default = false, but when object iherit IAnimatedSprite-> True;
	RECT *_rectRS;//NULL if object hasn't animated sprite
public:
	virtual char* className();
	ObjectGame(void);
	ObjectGame(int Kind, int Width, int Height, D3DXVECTOR3 pos);
	void UpdateRect();
	virtual void Update(DWORD deltatime) = 0;
	virtual void Update(DWORD Delta_Time, std::list<ObjectGame*> *_ListObjectCollision) = 0;
	~ObjectGame(void);
};

#endif // !__OBJECT_GAME__H__