#pragma once
#include "armure.h"
#include "arme.h"

class inventaire
{
private:
	armure *listArmure[emplacementarmuretaille];
	arme *slotArme;
public : 
	//instancie les tableau de pointeur a nullptr ( pas d'equipement)
	inventaire();
	armure *getArmure(emplacementarmure) const;
	arme *getArme() const;
	void setArmure(armure *);
	void setArme(arme *);
	int getSumArmor() const;
	int gettSumEva() const;
	int *getSumResistance() const;
	// renvoie la classeArmure de l'armure chest 
	classeArmure getClasseArmure() const;
	int getPrecision();
	degat getDegat();

};

