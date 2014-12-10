
#include "BUM.h"
class COMPOTE:public BUM
{
public:
	COMPOTE();
	void Sopport();
	void Set_x(int n);
	int Get_x();
	void Set_y(int n);
	int Get_y();
	~COMPOTE();
private:
	int x;
	int y;
};

