#include "inventaire.h"

inventaire::inventaire() 
{
	slotArme = new arme();
	for (int k = 0; k < emplacementarmuretaille; k++) {
		listArmure[k] = new armure();
	}
}


armure *inventaire::getArmure(emplacementarmure e) const
{
	return listArmure[static_cast<int>(e)];
}

arme *inventaire::getArme() const
{
	return slotArme;
}

void inventaire::setArmure(armure* a)
{
	emplacementarmure e;
	e = a->getEmplacement();
	listArmure[static_cast<int>(e)] = a;
}

void inventaire::setArme(arme* a)
{
	slotArme = a;
}

int inventaire::getSumArmor() const
{
	int sumArmor = 0;
	for (int k = 0; k < emplacementarmuretaille; k++)
	{
		sumArmor += listArmure[k]->getArmure();
	}
	return sumArmor;
}

int inventaire::gettSumEva() const
{
	int sumEva = 0;
	for (int k = 0; k < emplacementarmuretaille; k++)
	{
		sumEva += listArmure[k]->getEvasion();
	}
	return sumEva;
}

int *inventaire::getSumResistance() const
{
	int* sumRes = new int[dmagiquetaille];
	for (int j = 0; j < dmagiquetaille; j++) {
		sumRes[j] = 0;
	}
	for (int k = 0; k < emplacementarmuretaille; k++) {
		sumRes[static_cast<int>(dmagique::feu)] += listArmure[k]->getResistance(dmagique::feu);
		sumRes[static_cast<int>(dmagique::eau)] += listArmure[k]->getResistance(dmagique::eau);
		sumRes[static_cast<int>(dmagique::terre)] += listArmure[k]->getResistance(dmagique::terre);
		sumRes[static_cast<int>(dmagique::vent)] += listArmure[k]->getResistance(dmagique::vent);
		sumRes[static_cast<int>(dmagique::ombre)] += listArmure[k]->getResistance(dmagique::lumiere);
		sumRes[static_cast<int>(dmagique::lumiere)] += listArmure[k]->getResistance(dmagique::lumiere);
	}
	return sumRes;
}

classeArmure inventaire::getClasseArmure() const
{
	return listArmure[static_cast<int>(emplacementarmure::chest)]->getTypeArmure();
}
