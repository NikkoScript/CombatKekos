#include "inventaire.h"

inventaire::inventaire() 
{
	slotArme = nullptr;
	for (int k = 0; k < emplacementarmuretaille; k++) {
		listArmure[k] = nullptr;
	}
}

inventaire::inventaire(inventaire const& copy)
{
	if (copy.slotArme == nullptr)
		slotArme = nullptr;
	else 
		slotArme = new arme(*copy.slotArme);
	for (int k = 0; k < emplacementarmuretaille; k++) {
		if (copy.listArmure[k] == nullptr)
			listArmure[k] = nullptr;
		else
			listArmure[k] = new armure(*copy.listArmure[k]);
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

void inventaire::setEquipement(equipement* e)
{
	if (e->gettype() == typeequipement::arme)
		setArme((arme*)e);
	else if (e->gettype() == typeequipement::armure)
		setArmure((armure*)e);
}

int inventaire::getSumArmor() const
{
	int sumArmor = 0;
	for (int k = 0; k < emplacementarmuretaille; k++)
	{
		if (listArmure[k] != nullptr)
			sumArmor += listArmure[k]->getArmure();
	}
	return sumArmor;
}

int inventaire::gettSumEva() const
{
	int sumEva = 0;
	for (int k = 0; k < emplacementarmuretaille; k++)
	{
		if(listArmure[k]!=nullptr)
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
		if (listArmure[k] != nullptr) {
			sumRes[static_cast<int>(dmagique::feu)] += listArmure[k]->getResistance(dmagique::feu);
			sumRes[static_cast<int>(dmagique::eau)] += listArmure[k]->getResistance(dmagique::eau);
			sumRes[static_cast<int>(dmagique::terre)] += listArmure[k]->getResistance(dmagique::terre);
			sumRes[static_cast<int>(dmagique::vent)] += listArmure[k]->getResistance(dmagique::vent);
			sumRes[static_cast<int>(dmagique::ombre)] += listArmure[k]->getResistance(dmagique::lumiere);
			sumRes[static_cast<int>(dmagique::lumiere)] += listArmure[k]->getResistance(dmagique::lumiere);
		}
	}
	return sumRes;
}

classeArmure inventaire::getClasseArmure() const
{
	if (listArmure[static_cast<int>(emplacementarmure::chest)] != nullptr)
		return listArmure[static_cast<int>(emplacementarmure::chest)]->getTypeArmure();
	else
		return classeArmure::legere;
}

int inventaire::getPrecision()
{
	if (slotArme != nullptr)
		return slotArme->getprecision();
	return 0;
}

degat inventaire::getDegat()
{
	if (slotArme != nullptr)
		return slotArme->getdegat();
	return degat();
}
