#ifndef __FILE_UTILS__H__
#define __FILE_UTILS__H__

#include "ObjectFactoty.h"
#include <vector>
#include <hash_map>

#define fileImage "..\\Resource\\file\\Image3.csv"
#define fileSimon "..\\Resource\\file\\Simon.csv"

class FileUtils
{
public:
	static FileUtils* getInstance();
	void ReadFileCSV(char* fileName, ObjectFactory* objFactory);
	void ReadFileMap();
	void ReadFileImage();
	void LoadCSV();
	std::vector<std::string> Split(std::string s, char key);
protected:
private:
	static FileUtils* _instance;
	std::hash_map<int, ObjectFactory*> list_ObjFactory;
	FileUtils();
};

#endif // !__FILE_UTILS__H__