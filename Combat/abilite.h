#pragma once
#include "degat.h"
#include <string>
#include "personnage.h"
class abilite
{
protected:
	degat deg;
	//Warning :  le nom de la compétence doit être unique pour chaque compétences différentes
	std::string nom;
	float bonus;
	int consume;
	int cooldown;
	int lastuse;
public : 
	abilite();
	abilite(degat d, std::string n, int cons, int cd ,float b);
	//renvoi faux si en cooldown ( si lastuse >0)
	bool coolDown() const;
	//décrémente la derniere utilisation 
	void decrLastUse();
	float chanceToucher(personnage const& lanceur, personnage const& cible) const;
	int degatinflige(personnage const& lanceur, personnage const& cible) const;

	// return la réussite true : coup touche , false coup manqué
	// enleve la vie et l'energie au lanceur et cible
	// ne vérifie pas les conditions de lancé ( energie suffisante , cooldown )
	bool utiliser(personnage lanceur, personnage cible);
	bool isequal(std::string value);

};
bool operator==(abilite ab, std::string n);
