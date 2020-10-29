#include "Armurie.h"

Armurie::Armurie()
{
	ListeArme.reserve(10);
	ListeArmure.reserve(40);
}

Armurie::~Armurie()
{
	for (unsigned int k = 0; k < ListePointeurArme.size(); k++)
	{
		delete ListePointeurArme[k];
	}

	for (unsigned int j = 0; j < ListePointeurArmure.size(); j++) {
		delete ListePointeurArmure[j];
	}
}

bool Armurie::addArmure(armure value)
{
	//recherche si l'armure existe déja 
	for (unsigned int k = 0; k < ListeArmure.size(); k++) {
		if (ListeArmure[k] == value.getNom())
			return false;
	}
	ListeArmure.push_back(value);
	return true;
}

bool Armurie::addArme(arme value)
{
	for (unsigned int k = 0; k < ListeArme.size(); k++) {
		if (ListeArme[k] == value.getNom())
			return false;
	}
	ListeArme.push_back(value);
	return true;
}

armure* Armurie::createArmure(std::string nom)
{
	for (unsigned int k = 0; k < ListeArmure.size(); k++) {
		if (ListeArmure[k] == nom) {
			armure* res = new armure(ListeArmure[k]);
			ListePointeurArmure.push_back(res);
			return res;

		}
	}
	return nullptr;
}

arme* Armurie::createArme(std::string nom)
{
	for (unsigned int k = 0; k < ListeArme.size(); k++) {
		if (ListeArme[k] == nom) {
			arme* res = new arme(ListeArme[k]);
			ListePointeurArme.push_back(res);
			return res;

		}
	}
	return nullptr;
}
