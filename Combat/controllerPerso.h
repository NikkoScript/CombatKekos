#pragma once
#include "personnage.h"
#include "abilite.h"
#include <vector>
class controllerPerso
{
private:
	personnage *perso;
	std::vector<abilite> livresort;
public : 
	controllerPerso(personnage &p);
	void setPerso(personnage &p);
	personnage &getPerso() const;
	std::vector<abilite> getLivreSort() const;
	void addAbilite(abilite const& ab);
	abilite *searchabilite(std::string nom);


};

