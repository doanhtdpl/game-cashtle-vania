#ifndef __STRUCT_BOX__
#define __STRUCT_BOX__
//Struct dung de the hien lai gameObject
//Phuc vu cho viec xet va cham

struct Box
{
	Box()
	{
		x = y = 0;
		w = h = 0;
		vx = vy = 0;
	}

	Box(float _x, float _y, float _w, float _h, float _vx, float _vy)
	{
		x = _x;
		y = _y;
		w = _w;
		h = _h;
		vx = _vx;
		vy = _vy;
	}

	Box(float _x, float _y, float _w, float _h)
	{
		x = _x;
		y = _y;
		w = _w;
		h = _h;
		vx = 0.0f;
		vy = 0.0f;
	}

	float x; //vi tri tam
	float y; // vi tri tam object theo moi truong
	float w; // kich thuoc cua Object
	float h;

	float vx; // van toc cua Object. Neu la static Object = 0
	float vy;
};

#endif // !__STRUCT_BOX__


#ifndef __INTERFACE__COLLISION__H__
#define __INTERFACE__COLLISION__H__

class ICollision
{
public:
	// returns true if the boxes are colliding (velocities are not used)
	bool AABBCheck(Box b1, Box b2);

	// returns true if the boxes are colliding (velocities are not used)
	// moveX and moveY will return the movement the b1 must move to avoid the collision
	bool AABB(Box b1, Box b2, float& moveX, float& moveY);

	// returns a box the spans both a current box and the destination box
	Box GetSweptBroadphaseBox(Box box, float deltaTime);

	// performs collision detection on moving box b1 and static box b2
	// returns the time that the collision occured (where 0 is the start of the movement and 1 is the destination)
	// getting the new position can be retrieved by box.x = box.x + box.vx * collisiontime
	// normalx and normaly return the normal of the collided surface (this can be used to do a response)
	float SweptAABB(Box b1, Box b2, float& normalx, float& normaly, float deltaTime);
	
	Box SetBox(float _x, float _y, float _w, float _h, float _vx, float _vy);

	static ICollision* GetInstance();
protected:

private:
	static ICollision* _instance;
};
#endif // !__INTERFACE__COLLISION__H__