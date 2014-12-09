#ifndef MONSTR_H
#define MONSTR_H
#include "critter.h"
class Monstr:public Critter
{
public:
    Monstr();
    void Set_agrrange(int n);
    int Get_agrrange();

    virtual void Move(int h);

private:
    int heroin,
        agrrange;
};

#endif // MONSTR_H
