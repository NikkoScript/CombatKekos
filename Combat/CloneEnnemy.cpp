#include "CloneEnnemy.h"

CloneEnnemy::CloneEnnemy()
{
	ListePerso.reserve(10);
}

CloneEnnemy::~CloneEnnemy()
{
	for (unsigned int k = 0; k < ListePointeurPerso.size(); k++) {
		delete ListePointeurPerso[k];
	}
}

bool CloneEnnemy::addPerso(personnage val)
{
	for (unsigned int k = 0; k < ListePerso.size(); k++) {
		if (ListePerso[k] == val.getNom())
			return false;
	}
	ListePerso.push_back(val);
	return true;
}

personnage* CloneEnnemy::createPerso(std::string value)
{
	for (unsigned int k = 0; k < ListePerso.size(); k++) {
		if (ListePerso[k] == value) {
			personnage* res = new personnage(ListePerso[k]);
			ListePointeurPerso.push_back(res);
			return res;
		}
	}
	return nullptr;
}
