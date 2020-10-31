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
	// recherche l'equipement dans le sac est l'equipe sur le personnage retourne le boolean correspondant a la rr�susite de l'op�ration ( ajout si trouv� sinon RAF ) 
	bool equiper(equipement* e, personnage* p);
	// ajoute un equipement au sac si la ref n'est pas d�ja pr�sente, renvoit la r�ussite de l'op�ration 
	bool addequipement(equipement* e);

};

