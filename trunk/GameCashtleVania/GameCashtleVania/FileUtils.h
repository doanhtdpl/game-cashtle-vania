#ifndef __FILE_UTILS__H__
#define __FILE_UTILS__H__

#include "ObjectFactoty.h"
#include <vector>

#define fileImage ..\\Resource\\file\\Image.csv
#define fileSimon ..\\Resource\\file\\Simon.csv

class FileUtils
{
public:
	static FileUtils* getInstance();
	void ReadFileCSV();
	void ReadFileMap();
	void ReadFileImage();

protected:
private:

	static FileUtils* _instance;
	FileUtils();
};

#endif // !__FILE_UTILS__H__