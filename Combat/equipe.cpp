#include "equipe.h"

equipe::equipe(std::string nom)
{
	name = nom;
	for (int k = 0; k < 4; k++) {
		front[k] = nullptr;
		back[k] = nullptr;
	}
}

bool equipe::addFrontPerso(controllerPerso* perso)
{
	for (int k = 0; k < 4; k++) {
		if (front[k] == nullptr) {
			front[k] = perso;
			return true;
		}
	}
	return false;
}

bool equipe::addBackPerso(controllerPerso* perso)
{
	for (int k = 0; k < 4; k++) {
		if (back[k] == nullptr) {
			back[k] = perso;
			return true;
		}
	}
	return false;
}
