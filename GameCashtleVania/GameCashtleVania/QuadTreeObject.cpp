#include "QuadTreeObject.h"
#include "ManageSprite.h"
#include "TagClassName.h"

QuadTreeObject* QuadTreeObject::_instance = NULL;

QuadTreeObject* QuadTreeObject::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new QuadTreeObject();
	}
	return _instance;
}

QuadTreeObject::QuadTreeObject() : QuadTree()
{

}

QuadTreeObject::~QuadTreeObject()
{
}

void QuadTreeObject::loadObjectFromFile(std::string filePath)
{
	//load object
	this->mapObject.readMapFromFile(filePath);
}

//lay tat ca ID object co trong screen. dua vao mapObj de lay list ObjectGame
std::vector<ObjectGame*> QuadTreeObject::getObjectInScreen(RECT screen)
{
	std::vector<int>* listID = new std::vector<int>();
	getListIDInScreen(listID, screen);

	std::vector<ObjectGame*> listObj;

	//duyet list ID
	std::vector<int>::iterator it;
	it = listID->begin();
	int ID;
	ObjectGame* obj;
	while (it != listID->end())
	{
		//ID trong list object 
		ID = *it++;
		obj = mapObject.listObjectInMap.find(ID)->second;
		listObj.push_back(obj);
	}

	return listObj;
}

void QuadTreeObject::draw(RECT screen)
{
	//lay ID object trong man hinh
	std::vector<int>* listID = new std::vector<int>();
	getListIDInScreen(listID, screen);


	//duyet list ID
	std::vector<int>::iterator it;
	it = listID->begin();
	int ID;
	ObjectGame* obj;
	while (it != listID->end())
	{
		//ID trong list object 
		ID = *it++;
		//lay object dua vao ID
		obj = mapObject.listObjectInMap.find(ID)->second;

		//draw
		if (obj->className() != TagClassName::getInstance()->tagHideObject)
		{
			ManageSprite::createInstance()->drawObject(obj);
		}	
	}

	////lay tat ca object game trong man hinh
	//std::vector<ObjectGame*> listObj = this->getObjectInScreen(Screen);
	//
	////duyet va ve
	//std::vector<ObjectGame*>::iterator it;
	//it = listObj.begin();
	//while(it != listObj.end())
	//{
	//	ObjectGame
	//}

}

void QuadTreeObject::upDateQNode(QNode* Node)
{
	int ID_tl = Node->ID * 8 + 1;
	int ID_tr = Node->ID * 8 + 2;
	int ID_bl = Node->ID * 8 + 3;
	int ID_br = Node->ID * 8 + 4;
	if (Node->_listID.size() == 0)//khong phai node la
	{
		if (Node->tl != NULL)
		{
			upDateQNode(Node->tl);
		}

		if (Node->tr != NULL)
		{
			upDateQNode(Node->tr);
		}

		if (Node->bl != NULL)
		{
			upDateQNode(Node->bl);
		}

		if (Node->br != NULL)
		{
			upDateQNode(Node->br);
		}
	}else
	{
		if(!Node->_listID.empty())
		{
			//duyet tat ca ID cua node. voi moi ID -> kiem tra xem object do da chet chua. Neu die thi remove.
			
			std::vector<int>::iterator it;
			it = Node->_listID.begin();
			while (it != Node->_listID.end())
			{
				int IDObject = *it;
				//lay Object bang ID
				ObjectGame* obj = this->mapObject.listObjectInMap.find(IDObject)->second;

				//kiem tra no con song hay ko?
				if (!obj->_isALive)
				{
					//chet roi
					Node->_listID.erase(it);
				}
				it++;
			}

			//for (; t != Node->ListObject->end();)
			//{
			//	ObjectGame * ob = *t;
			//	if (!ob->_isALive)
			//	{
			//		Node->ListObject->erase(t++);
			//	}else
			//	{//only update with dynamic Object
			//		if (ob->_kind >= 100 || ob->className() == "Mario")
			//		{
			//			if (!Node->IsBound(Node->rect, ob->_rect))//if Node doesn't contain ob
			//			{
			//				Node->ListObject->erase(t);//erase ob
			//				this->AddObjectToQuadTree(ob);//add to quadtree
			//			}
			//		}

			//		//list_ObjectScreen->push_back(ob);
			//		++t;
			//	}
			//}
		}
	}
}

void QuadTreeObject::upDateQuadTree()
{
	this->upDateQNode(this->root);
}

void QuadTreeObject::addObjectToQuadTree(ObjectGame* object)
{
	//add objet vao hash map trong mapObject. Sau do add id vao node
	int IDMax = mapObject.getIDMaxInList() + 1;
	mapObject.listObjectInMap[IDMax] = object;
	this->addObjectToNode(this->root, object, IDMax);
}

void QuadTreeObject::addObjectToNode(QNode* Node, ObjectGame* object, int IDObjInList)
{
		int ID_tl = Node->ID * 8 + 1;
		int ID_tr = Node->ID * 8 + 2;
		int ID_bl = Node->ID * 8 + 3;
		int ID_br = Node->ID * 8 + 4;
		if (Node->_listID.size() == 0)//khong phai node la
		{
			if (Node->tl != NULL)
			{
				if (Node->tl->isBound(Node->tl->rect, object->_rect))
				{
					addObjectToNode(Node->tl, object, IDObjInList);
					return;
				}
			}
	
			if (Node->tr != NULL)
			{
				if (Node->tr->isBound(Node->tr->rect, object->_rect))
				{
					addObjectToNode(Node->tr, object, IDObjInList);
					return;
				}
			}
	
			if (Node->bl != NULL)
			{
				if (Node->bl->isBound(Node->bl->rect, object->_rect))
				{
					addObjectToNode(Node->bl, object, IDObjInList);
					return;
				}
			}
	
			if (Node->br != NULL)
			{
				if (Node->br->isBound(Node->br->rect, object->_rect))
				{
					addObjectToNode(Node->br, object, IDObjInList);
					return;
				}
			}
		}
		
		//add ID cua obj vao node
		Node->_listID.push_back(IDObjInList);
}
