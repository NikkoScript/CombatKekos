#pragma once
#include <vector>
#include "armure.h"
#include "arme.h"
// class factory equipement. ( stocke des équipement pour gérér des références à supprimer lors du déchargement ) 
class Armurie
{
private:
	std::vector<armure> ListeArmure;
	std::vector<arme> ListeArme;
	// liste des instances créer par les méthodes create
	std::vector<armure*> ListePointeurArmure;
	std::vector<arme*> ListePointeurArme;
public:
	Armurie();
	~Armurie();
	// methode ad : return l'état de création ( true si créer, false sinon) , ajoute l'armrue seulemeent si elle 'y est pas présente.
	bool addArmure(armure value);
	bool addArme(arme value);
	// renvoi un nouveau pointeur vers un equipement avec le nom correspondant. nullptr si non trouvé
	armure* createArmure(std::string nom);
	arme* createArme(std::string nom);


};

