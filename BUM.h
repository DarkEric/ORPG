#ifndef BUM_H
#define BUM_H
#include "NPC.h"
#include <string>
class BUM:public NPC
{
public:
	BUM();
    void Dialog(int i);
	virtual void Set_x(int n);
	virtual int Get_x();
	virtual void Set_y(int n);
	virtual int Get_y();
	~BUM();
private:
	int x;
	int y;
    std::string name;
};
#endif
