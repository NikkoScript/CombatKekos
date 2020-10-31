#pragma once
#include <vector>
#include "equipement.h"
#include "personnage.h"
class sacInventaire
{
private:
	std::vector<equipement*> equipSac;
	std::vector<personnage*> equipBy;
public:
	std::vector<arme*> getListArme() const;
	std::vector<armure*> getListArmure() const;
	// recherche l'equipement dans le sac est l'equipe sur le personnage retourne le boolean correspondant a la rrésusite de l'opération ( ajout si trouvé sinon RAF ) 
	bool equiper(equipement* e, personnage* p);
	// ajoute un equipement au sac si la ref n'est pas déja présente, renvoit la réussite de l'opération 
	bool addequipement(equipement* e);

};

