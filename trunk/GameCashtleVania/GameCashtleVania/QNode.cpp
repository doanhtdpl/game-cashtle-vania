#include "QNode.h"


QNode::QNode(void)
{
}

QNode::QNode(int ID, int x, int y, int widht, int height)
{
	this->ID  = ID;
	this->_x = x;
	this->_y = y;
	this->_width  =widht;
	this->_height = height;

	rect.left = x;
	rect.right = x + this->_width;
	rect.top = y + this->_height;
	rect.bottom = y;

	//this->ListObject = new list<ObjectGame* >;
	
	this->tl = NULL;
	this->tr = NULL;
	this->bl = NULL;
	this->br = NULL;
}

void QNode::addIDToList(int ID)
{
	this->_listID.push_back(ID);
}

void QNode::getListIDInScreen(std::vector<int>* listIDInScreen, RECT Screen)
{
	//std::vector<int> listIDInScreen;

	if ( isBound(Screen, this->rect) )
	{//co giao nhau
		if ( this->_listID.size() == 0 ) // khong phai node la
		{
			if (this->tl != NULL)
				this->tl->getListIDInScreen(listIDInScreen, Screen);

			if (this->tr != NULL)
				this->tr->getListIDInScreen(listIDInScreen, Screen);

			if (this->bl != NULL)
				this->bl->getListIDInScreen(listIDInScreen, Screen);

			if (this->br != NULL)
				this->br->getListIDInScreen(listIDInScreen, Screen);
		}
		else//node la
		{
			//node co chua object
			if (!_listID.empty())
			{
				//add tat ca ID cua node vao list
				std::vector<int>::iterator t;
				t = this->_listID.begin();
				while (t != this->_listID.end())
				{
					int ID = *t++;
					//listIDInScreen->
					//kiem tra list object da chua ID nay chua
					if (std::find(listIDInScreen->begin(), listIDInScreen->end(), ID) == listIDInScreen->end())
					{
						listIDInScreen->push_back(ID);
					}
				}
			}
		}
	}
}

//void QNode::getListObInScreen(std::vector<ObjectGame*> list_ObjectScreen, RECT Screen)
//{
//	if ( isBound(Screen, this->rect) )
//	{//co giao nhau
//		if ( this->_listObject.size() == 0 ) // khong phai node la
//		{
//			if (this->tl != NULL)
//				this->tl->getListObInScreen(list_ObjectScreen, Screen);
//
//			if (this->tr != NULL)
//				this->tr->getListObInScreen(list_ObjectScreen, Screen);
//
//			if (this->bl != NULL)
//				this->bl->getListObInScreen(list_ObjectScreen, Screen);
//
//			if (this->br != NULL)
//				this->br->getListObInScreen(list_ObjectScreen, Screen);
//		}
//		else//node la
//		{
//			//node co chua object
//			if (!_listObject.empty())
//			{
//				std::vector<ObjectGame*>::iterator t;
//				t = this->_listObject.begin();
//				for (; t != this->_listObject.end();)
//				{
//					ObjectGame * ob = *t;
//					if (!ob->_isALive)
//					{
//						_listObject.erase(t++);
//					}else
//					{
//						
//						if ( isBound(Screen, ob->_rect) )
//						{
//							list_ObjectScreen.push_back(ob);
//						}
//						++t;
//					}
//				}
//			}
//			
//			//this->ListObject->
//		}
//	}
//}

//kiem tra 2 hinh chu nhat co giao nhau
bool QNode::isBound(RECT rect1, RECT rect2)
{
	int L, R, T, B;
	
	if (rect1.left < rect2.left)
		L = rect2.left;
	else
		L = rect1.left;

	if (rect1.right < rect2.right)
		R = rect1.right;
	else
		R = rect2.right;

	if (rect1.top < rect2.top)
		T = rect1.top;
	else
		T = rect2.top;

	if (rect1.bottom < rect2.bottom)
	{	
		B = rect2.bottom;
	}
	else
	{
		B = rect1.bottom;
	}

	if (L < R && T > B)
	{
		return true;
	}else
	{
		return false;
	}
}


QNode::~QNode()
{
	if (tl != NULL)
		delete tl;
	if (tr != NULL)
		delete tr;
	if (bl != NULL)
		delete bl;
	if (br != NULL)
		delete br;
}