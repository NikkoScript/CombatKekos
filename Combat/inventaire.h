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
	// n'est pas responsable de la création et destruction des équipements
	inventaire();
	inventaire(inventaire const& copy);
	armure *getArmure(emplacementarmure) const;
	arme *getArme() const;
	void setArmure(armure *);
	void setArme(arme *);
	//recoit en paramêtre un equiepement et l'equipe
	void setEquipement(equipement*);
	int getSumArmor() const;
	int gettSumEva() const;
	int *getSumResistance() const;
	// renvoie la classeArmure de l'armure chest 
	classeArmure getClasseArmure() const;
	int getPrecision();
	degat getDegat();

};

