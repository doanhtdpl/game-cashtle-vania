#ifndef __OBJECT_FACTORY_H__
#define __OBJECT_FACTORY_H__
#include "ObjectGame.h"
#include <vector>
#include <string>

class ObjectFactory
{
public:
	void addInfo(std::vector<std::string> arr);
	virtual ObjectGame* createObj();

	//tao doi tuong dua vao info load len tu file
	virtual ObjectGame* createObj(int ID);

	//tao doi tuong dua vao info load len tu map
	virtual ObjectGame* createObj(std::vector<std::string> arr);
	
	//doc tu file len. Luu trong tin ID - IDImage - Width - Height luu trong info
	virtual std::vector<std::string> getInfoByID(int ID);
protected:
	// vector chua list cac arr : std::vector<std::string> la thong tin cua 1 object
	std::vector<std::vector<std::string>> info;
private:
};
#endif // !__OBJECT_FACTORY_H__