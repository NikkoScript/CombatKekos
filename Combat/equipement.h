#pragma once
#include "caracteristique.h"
#include <string>
class equipement
{ 
private : 
	//caracBonus : stats bonus appliqué au personage , caracBase : prerequis matos
	caracteristique stat;
	int duramax, duraact;
	std::string nom;
	
public :
	equipement();
	equipement(caracteristique , std::string);
	/*repare equipement de la valeur en parametre
	renvoi la valeur modifié*/
	int reparer(int);
	/*fonction permettant de savoir si un equipement est equipable par un personnage*/
	bool isEquipable(caracteristique) const ;
	bool isBreakable() const;
	int useDura(int);
	std::string getNom() const;
	bool isequal(std::string value);
};
bool operator==(equipement e, std::string v);

