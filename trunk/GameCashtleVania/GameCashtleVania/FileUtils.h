#ifndef __FILE_UTILS__H__
#define __FILE_UTILS__H__

#include "ObjectFactoty.h"
#include <vector>
#include <hash_map>

#define fileImage "..\\Resource\\file\\Image.csv"
#define fileSimon "..\\Resource\\file\\Simon.csv"
#define fileIronRod "..\\Resource\\file\\IronRod.csv"
#define fileGroundBG "..\\Resource\\file\\GroundBG.csv"

class FileUtils
{
public:
	static FileUtils* getInstance();
	void readFileCSV(char* fileName, ObjectFactory* objFactory);
	void readFileMap();
	void readFileImage();
	void loadCSV();
	std::vector<std::string> split(std::string s, char key);
protected:
private:
	static FileUtils* _instance;
	std::hash_map<int, ObjectFactory*> list_ObjFactory;
	FileUtils();
};

#endif // !__FILE_UTILS__H__