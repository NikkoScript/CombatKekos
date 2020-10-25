#include "controllerPerso.h"

controllerPerso::controllerPerso(personnage *p)
{
	perso = p;
	livresort.reserve(10);
}

void controllerPerso::setPerso(personnage *p)
{
	perso = p;
}

personnage *controllerPerso::getPerso() const
{
	return perso;
}

std::vector<abilite> controllerPerso::getLivreSort() const
{
	return livresort;
}

void controllerPerso::addAbilite(abilite const& ab)
{
	livresort.push_back(ab);
}

abilite* controllerPerso::searchabilite(std::string nom)
{
	for (unsigned int k = 0; k < livresort.size(); k++) {
		if (livresort[k] == nom)
			return &livresort[k];
	}
	return nullptr;
}
