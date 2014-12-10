#pragma once
#include "NPC.h"
class BUM:public NPC
{
public:
	BUM();
	void Dialog();
	virtual void Set_x(int n);
	virtual int Get_x();
	virtual void Set_y(int n);
	virtual int Get_y();
	~BUM();
private:
	int x;
	int y;
};

