#pragma once
#include "degat.h"
#include <string>
#include "personnage.h"
class abilite
{
protected:
	degat deg;
	//Warning :  le nom de la comp�tence doit �tre unique pour chaque comp�tences diff�rentes
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
	//d�cr�mente la derniere utilisation 
	void decrLastUse();
	float chanceToucher(personnage const& lanceur, personnage const& cible) const;
	int degatinflige(personnage const& lanceur, personnage const& cible) const;

	// return la r�ussite true : coup touche , false coup manqu�
	// enleve la vie et l'energie au lanceur et cible
	// ne v�rifie pas les conditions de lanc� ( energie suffisante , cooldown )
	bool utiliser(personnage lanceur, personnage cible);
	bool isequal(std::string value);

};
bool operator==(abilite ab, std::string n);
