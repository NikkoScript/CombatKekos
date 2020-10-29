#pragma once
#include <vector>
#include "personnage.h"
class CloneEnnemy
{
private:
	std::vector<personnage> ListePerso;
	std::vector<personnage*> ListePointeurPerso;
public:
	CloneEnnemy();
	~CloneEnnemy();
	bool addPerso(personnage val);
	personnage* createPerso(std::string value);
};

