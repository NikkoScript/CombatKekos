#pragma once
#include "controllerPerso.h"
#include <string>
class equipe
{
private:
	controllerPerso *front[4];
	controllerPerso* back[4];
	std::string name;
public : 
	// constructeur: innitialise les deux tableau a nullptr
	equipe(std::string nom);
	// ajoute un personnage à l'avant, renvoi true si ajout, false si tableau complet
	bool addFrontPerso(controllerPerso* perso);
	bool addBackPerso(controllerPerso* perso);
	controllerPerso* getFront(int k);
	controllerPerso* getBack(int k);


};

