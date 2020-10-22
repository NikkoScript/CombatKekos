#pragma once
#include "caracteristique.h"
#include "degat.h"
#include <string>
#include "inventaire.h"


class personnage
{
private : 
	inventaire inv;
	caracteristique carac;
	int vieMax;
	int vieAct;
	int energieMax;
	int energieAct;
	std::string nom;

public: 
	personnage();
	personnage(std::string);
	caracteristique getcarac() const;
	bool isalive() const;
	int getVieMax() const;
	int getVieAct() const;
	int getEnergieMax() const;
	int getEnergieact() const; 
	std::string getNom() const;
	inventaire getInv() const;
	int consume(int c);


	// param: int degat infligé 
	//return : valeur modifié des pv
	int infligedegat(int);
};

