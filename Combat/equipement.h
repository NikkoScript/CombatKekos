#pragma once
#include "caracteristique.h"
#include <string>
enum class typeequipement{arme,armure};
class equipement
{ 
private : 
	//caracBonus : stats bonus appliqué au personage , caracBase : prerequis matos
	caracteristique stat;
	int duramax, duraact;
	std::string nom;
	typeequipement type;
	
public :
	equipement();
	equipement(caracteristique , std::string);
	equipement(caracteristique c, std::string n, typeequipement t);
	virtual ~equipement();
	/*repare equipement de la valeur en parametre
	renvoi la valeur modifié*/
	int reparer(int);
	/*fonction permettant de savoir si un equipement est equipable par un personnage*/
	bool isEquipable(caracteristique) const ;
	bool isBreakable() const;
	int useDura(int);
	typeequipement gettype();
	std::string getNom() const;
	bool isequal(std::string value);
};
bool operator==(equipement e, std::string v);

