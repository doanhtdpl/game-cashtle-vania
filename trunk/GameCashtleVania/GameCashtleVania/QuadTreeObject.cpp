#include "QuadTreeObject.h"
#include "ManageSprite.h"
#include "TagClassName.h"
#include "ManageGame.h"

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
	this->mapObject.listObjectInMap.clear();
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

	//dua vao listID thi vao mapObject de lay list Object thuoc sceen
	std::vector<ObjectGame*> listObj = this->mapObject.getListObjectinScreen(*listID);

	listID->clear();
	delete listID;
	////duyet list ID
	//std::vector<int>::iterator it;
	//it = listID->begin();
	//int ID;
	//ObjectGame* obj = NULL;
	//while (it != listID->end())
	//{
	//	//ID trong list object 
	//	ID = *it++;
	//	std::hash_map< int, ObjectGame*>::iterator itObject = mapObject.listObjectInMap.find(ID);
	//	if (itObject != mapObject.listObjectInMap.end())
	//	{
	//		obj = mapObject.listObjectInMap.find(ID)->second;
	//	}
	//	 
	//	if (obj != NULL)
	//	{
	//		listObj.push_back(obj);
	//	}
	//	
	//}

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
	ObjectGame* obj = NULL;
	while (it != listID->end())
	{
		//ID trong list object 
		ID = *it++;
		//lay object dua vao ID
		std::hash_map< int, ObjectGame*>::iterator itObject = mapObject.listObjectInMap.find(ID);
		if (itObject != mapObject.listObjectInMap.end())
		{
			obj = mapObject.listObjectInMap.find(ID)->second;
			//draw
			if (obj != NULL)
			{
				if (obj->className() != TagClassName::getInstance()->tagHideObject)
				{
					ManageSprite::createInstance()->drawObject(obj);
				}	
			}
		}
	}

	//delete obj;
	listID->clear();
	delete listID;

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
			ObjectGame* obj;
			while (it != Node->_listID.end())
			{
				int IDObject = *it++;
				//lay Object bang ID
				std::hash_map< int, ObjectGame*>::iterator itListObj = this->mapObject.listObjectInMap.find(IDObject);
				if (itListObj != this->mapObject.listObjectInMap.end())
				{
					obj = itListObj->second;

					//kiem tra no con song hay ko?
					if (obj == NULL)
					{
						//xem chung viec xoa
						//itListObj = this->mapObject.listObjectInMap.erase(itListObj);
						//this->mapObject.eraseObject(IDObject);
						it = Node->_listID.erase(it);
						//it--;
					}
					else
					{
						if (!obj->_isALive)
						{
							//chet roi
							//this->mapObject.listObjectInMap.erase(IDObject);
							this->mapObject.eraseObject(IDObject);
							delete obj;
							it = Node->_listID.erase(it);
						}else
						{
							++it;
						}
					}
				}
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

void QuadTreeObject::upDateQuadTree(RECT screen)
{
	//this->upDateQNode(this->root);

	//duyet listObjectInMap. Nhung Object nao ko ton tai thi xoa di
	std::hash_map< int, ObjectGame*>::iterator it = this->mapObject.listObjectInMap.begin();
	ObjectGame* obj = NULL;
	while (it != this->mapObject.listObjectInMap.end())
	{
		obj = it->second;
		if (!obj->_isALive)
		{
			//xoa object ra khoi quadtree
			this->eraseObject(it->first);

			//xoa khoi listObj
			it = this->mapObject.listObjectInMap.erase(it);
			//xoa IDHashMap cua Object ra khoi Quadtree
			//it++;
		
		}else
		{
			//neu van thuoc trong man hinh ma la enemy thi kiem tra no con va cham voi node chua no ko
			if (obj->className() == TagClassName::getInstance()->tagEnemy)
			{
				//tim nhung node co chua no
				QNode* node = NULL;
				//duyet tat ca node. 
				for (std::hash_map< int, QNode*>::iterator itNode = this->listQNode.begin(); itNode != listQNode.end();)
				{
					node = itNode->second;
					int ID_HashMapOfObj = it->first;
					if (node->findIDObj(it->first))
					{
						//neu node co chua enemy thi kiem tra enemy co con nam trong do ko? neu ko thi xoa va add vao lai
						if (!QNode::isBound(node->rect, obj->getRect()))
						{
							//neu node ko con chua obj nua
							this->eraseObject(it->first);
							
							//sau do add vao lai node root
							this->addObjectToNode(this->root, obj, it->first);
						}
					}
					itNode++;
				}
			}

			it ++;
		}

	}
}

void QuadTreeObject::eraseObject(int IDinMap)
{
	QNode* node = NULL;
	//duyet tat ca node. 
	for (std::hash_map< int, QNode*>::iterator it = this->listQNode.begin(); it != listQNode.end();)
	{
		node = it->second;
		if (node->eraseIDObj(IDinMap))
		{
			//xoa thanh cong
		}
		it ++;
	}
	
	//xoa trong list Object
	//this->mapObject.eraseObject(IDinMap);
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
				if (Node->tl->isBound(Node->tl->rect, object->getRect()))
				{
					addObjectToNode(Node->tl, object, IDObjInList);
					return;
				}
			}
	
			if (Node->tr != NULL)
			{
				if (Node->tr->isBound(Node->tr->rect, object->getRect()))
				{
					addObjectToNode(Node->tr, object, IDObjInList);
					return;
				}
			}
	
			if (Node->bl != NULL)
			{
				if (Node->bl->isBound(Node->bl->rect, object->getRect()))
				{
					addObjectToNode(Node->bl, object, IDObjInList);
					return;
				}
			}
	
			if (Node->br != NULL)
			{
				if (Node->br->isBound(Node->br->rect, object->getRect()))
				{
					addObjectToNode(Node->br, object, IDObjInList);
					return;
				}
			}
		}else
		{
			//add ID cua obj vao node
			Node->_listID.push_back(IDObjInList);
		}
		
}

void QuadTreeObject::clearDataQuadtree()
{
	QuadTree::clearDataQuadtree();

	for (hash_map<int, ObjectGame*>::iterator it = this->mapObject.listObjectInMap.begin(); it != this->mapObject.listObjectInMap.end(); )
	{
		this->eraseObject(it->first);
		it++;
	}

	this->mapObject.listObjectInMap.clear();
}