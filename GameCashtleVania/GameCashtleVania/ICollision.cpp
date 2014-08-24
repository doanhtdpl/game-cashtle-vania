#include "ICollision.h"
#include <iostream>

ICollision* ICollision::_instance = NULL;

ICollision* ICollision::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new ICollision();
	}

	return _instance;
}

Box ICollision::setBox(float _x, float _y, float _w, float _h, float _vx, float _vy)
{
	return Box(_x, _y, _w, _h, _vx, _vy);
}

//return true neu 2 box dang va cham
// moveX va moveY tra va huong ma box di chuyeb de tranh va cham
bool ICollision::AABB(Box b1, Box b2, float& moveX, float& moveY)
{
	moveX = moveY = 0;

				// left - right
	float l = ( b2.x - b2.w / 2) - ( b1.x + b1.w / 2 );// 
	
				//right - left
	float r = ( b2.x + b2.w / 2 ) - ( b1.x - b1.w / 2 ); //
	
				// botton - top
	float t = ( b2.y - b2.h / 2) - ( b1.y + b1.h / 2 );
	
				//top - botton
	float b = ( b2.y + b2.h / 2 ) - ( b1.y - b1.h / 2);

	// check that there was a collision
	if (l > 0 || r < 0 || t > 0 || b < 0)
		return false;//neu khong co va cham

	// find the offset of both sides
	// tim khoang cach di chuyen de khong bi va cham
	moveX = abs(l) < abs(r) ? l : r;
	moveY = abs(t) < abs(b) ? t : b;

	// only use whichever offset is the smallest
	// chi su dung 1 phan dich chuyen nho hon
	if (abs(moveX) < abs(moveY))
		moveY = 0.0f;
	else
		moveX = 0.0f;

	return true;
}

bool ICollision::AABBCheck(Box b1, Box b2)
{
	return !( (b1.x + b1.w / 2) < (b2.x - b2.w / 2) || (b1.x - b1.w / 2) > (b2.x + b2.w / 2) 
			|| (b1.y + b1.h / 2) < (b2.y - b2.h / 2) || (b1.y - b1.h / 2) > (b2.y + b2.h / 2));
}

// returns a box the spans both a current box and the destination box
Box ICollision::getSweptBroadphaseBox(Box box, float deltaTime)
{
	Box broadphasebox(0.0f, 0.0f, 0.0f, 0.0f);

	broadphasebox.x = box.vx > 0 ? box.x : box.x + box.vx * deltaTime;
	broadphasebox.y = box.vy > 0 ? box.y : box.y + box.vy * deltaTime;
	broadphasebox.w = box.vx > 0 ? box.vx * deltaTime + box.w : box.w - box.vx * deltaTime;
	broadphasebox.h = box.vy > 0 ? box.vy * deltaTime + box.h : box.h - box.vy * deltaTime;

	return broadphasebox;
}

//va cham voi b2 dung yen
float ICollision::sweptAABB(Box b1, Box b2, float& normalx, float& normaly, float deltaTime)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	// find the distance between the objects on the near and far sides for both x and y
	if (b1.vx > 0.0f)
	{
		// box 1 moving from left to right
		// left of box 2 - right of box 1
		xInvEntry = (b2.x - b2.w / 2) - (b1.x + b1.w / 2);

		// right of box 2 - left of box 1
		xInvExit = (b2.x + b2.w / 2) - (b1.x - b1.w / 2);
	}
	else 
	{
		// box 1 moving from right to left
		// right of box 2 - left of box 1
		xInvEntry = (b2.x + b2.w / 2) - (b1.x - b1.w / 2);

		// left of box 2 - right of box 1
		xInvExit = (b2.x - b2.w / 2) - (b1.x + b1.w / 2);
	}

	if (b1.vy > 0.0f)
	{
		// box 1 moving from botton to top
		// botton of b2 - top of box 1
		yInvEntry = (b2.y - b2.h / 2) - (b1.y + b1.h / 2);

		// top of b2 - botton of b1
		yInvExit = (b2.y + b2.h / 2) - (b1.y - b1.h / 2);
	}
	else
	{
		// box 1 moving from top to botton
		// top of box 2 - botton of box 1
		yInvEntry = (b2.y + b2.h / 2) - (b1.y - b1.h / 2);

		// botton of box 2  - top of box 1
		yInvExit = (b2.y - b2.h / 2) - (b1.y + b1.h / 2);
	}

	// find time of collision and time of leaving for each axis (if statement is to prevent divide by zero)
	// tim thoi gian va cham va thoi gian het va cham
	float xEntry, yEntry;
	float xExit, yExit;

	if (b1.vx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / (b1.vx * deltaTime);
		xExit = xInvExit / (b1.vx * deltaTime);
	}

	if (b1.vy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / (b1.vy * deltaTime);
		yExit = yInvExit / (b1.vy * deltaTime);
	}

	// find the earliest/latest times of collision
	// 
	//std::min
	float entryTime = std::max(xEntry, yEntry);
	float exitTime = std::min(xExit, yExit);

	// if there was no collision
	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}
	else // if there was a collision
	{        		
		// calculate normal of collided surface
		if (xEntry > yEntry)
		{
			//va cham theo truc x
			if (xInvEntry < 0.0f)
			{
				//va cham ben trai
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else
			{
				//va cham ben phai
				normalx = -1.0f;
				normaly = 0.0f;
			}
		}
		else
		{
			//va cham theo truc y
			if (yInvEntry < 0.0f)
			{
				// va cham phia duoi
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else
			{
				// va cham phia tren
				normalx = 0.0f;
				normaly = -1.0f;
			}
		}

		// return the time of collision
		return entryTime;
	}
}