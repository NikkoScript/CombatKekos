#pragma once
#include <vector>
#include "armure.h"
#include "arme.h"
// class factory equipement. ( stocke des �quipement pour g�r�r des r�f�rences � supprimer lors du d�chargement ) 
class Armurie
{
private:
	std::vector<armure> ListeArmure;
	std::vector<arme> ListeArme;
	// liste des instances cr�er par les m�thodes create
	std::vector<armure*> ListePointeurArmure;
	std::vector<arme*> ListePointeurArme;
public:
	Armurie();
	~Armurie();
	// methode ad : return l'�tat de cr�ation ( true si cr�er, false sinon) , ajoute l'armrue seulemeent si elle 'y est pas pr�sente.
	bool addArmure(armure value);
	bool addArme(arme value);
	// renvoi un nouveau pointeur vers un equipement avec le nom correspondant. nullptr si non trouv�
	armure* createArmure(std::string nom);
	arme* createArme(std::string nom);


};

