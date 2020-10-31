#pragma once
#include <vector>
#include "equipement.h"
#include "personnage.h"
class sacInventaire
{
private:
	std::vector<equipement*> equipSac;
	std::vector<personnage*> equipBy;
};

