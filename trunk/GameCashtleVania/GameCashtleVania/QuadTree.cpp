#include "QuadTree.h"
using namespace std;
#include "FileUtils.h"

QuadTree::QuadTree(void)
{
}

QuadTree::~QuadTree(void)
{
	delete this->root;
	this->listQNode.clear();
}

void QuadTree::loadMap()
{
	loadObjectFromFile(fileMap);
	loadListQNodeFromFile(fileQuadtree);
	this->root = this->listQNode.find(1)->second;
	buildQuadTree(root);
}

void QuadTree::loadListQNodeFromFile(std::string filePath)
{
	vector<vector<string>> info = FileUtils::readFile(filePath, '\t');

	//duyet bang iterator
	vector<vector<string>>::iterator it;
	vector<string> arr;
	it = info.begin();

	while (it != info.end())
	{
		arr = *it++;
		//int ID_Node, x_node, y_node, width;
		int k = 0;
		while(arr.at(0)[k] < 48 || arr.at(0)[k] > 57)
		{
			arr.at(0).erase(arr.at(0).begin());
		}

		int ID_Node = std::atoi(arr.at(0).c_str());
		int x_node = std::atoi(arr.at(1).c_str());
		int y_node = std::atoi(arr.at(2).c_str());
		int width = std::atoi(arr.at(3).c_str());
		int height = std::atoi(arr.at(4).c_str()); 

		QNode* node = new QNode(ID_Node, x_node, y_node, width, width);
		
		//them tat cac ID object vao node
		for (int i = 5; i < arr.size(); i++)
		{
			int ID_Object = atoi(arr.at(i).c_str());
			node->addIDToList(ID_Object);
		}

		//add node vao hash map
		this->listQNode[ID_Node] = node;
	}
}

void QuadTree::buildQuadTree(QNode*& node)
{
	int ID_tl = node->ID * 8 + 1;
	int ID_tr = node->ID * 8 + 2;
	int ID_bl = node->ID * 8 + 3;
	int ID_br = node->ID * 8 + 4;

	//tim kiem 4 node con cua no co trong listNode hay ko? Neu co build
	searchIDNodeInList(node->tl, ID_tl);
	searchIDNodeInList(node->tr, ID_tr);
	searchIDNodeInList(node->bl, ID_bl);
	searchIDNodeInList(node->br, ID_br);
}

void QuadTree::searchIDNodeInList(QNode*& node, int ID)
{
	std::hash_map<int, QNode*>::iterator it;
	it = this->listQNode.find(ID);
	if (it != this->listQNode.end())
	{
		node = it->second;
		buildQuadTree(node);
	}else
	{
		//neu khong ton tai node thi khong lam gi ca
		node = NULL;
	}
}

void QuadTree::getListIDInScreen(std::vector<int> *listID, RECT Screen)
{
	this->root->getListIDInScreen(listID, Screen);
}

void QuadTree::clearDataQuadtree()
{
	delete this->root;
	this->listQNode.clear();
}