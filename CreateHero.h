#ifndef CREATEHERO_H
#define CREATEHERO_H
#include "berserk.h"
#include "Consol.h"
#include "Game.h"

Hero* NewHero(int,std::string);

std::string EnterName();

int SelectNewHero();

void CreateHero();

#endif // CREATEHERO_H
