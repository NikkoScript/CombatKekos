#pragma once
#include "equipe.h"
class combat
{
private:
	equipe *joueur;
	equipe *ennemy;
	int nbTour;
public:
	combat(equipe* j, equipe* e);

};

