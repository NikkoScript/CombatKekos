#include "personnage.h"

personnage::personnage() : carac(),vieMax(100),vieAct(100),energieAct(100),energieMax(100),nom("")
{
}

personnage::personnage(std::string n) :  carac(), vieMax(100), vieAct(100), energieAct(100), energieMax(100), nom(n)
{
}

caracteristique personnage::getcarac() const
{
	return carac;
}

bool personnage::isalive() const
{
	if (vieAct > 0)
		return true;
	else
		return false;
}

int personnage::getVieMax() const
{
	return vieMax;
}

int personnage::getVieAct() const
{
	return vieAct;
}

int personnage::getEnergieMax() const
{
	return energieMax;
}

int personnage::getEnergieact() const
{
	return energieAct;
}

std::string personnage::getNom() const
{
	return nom;
}

inventaire personnage::getInv() const
{
	return inv;
}

int personnage::consume(int c)
{
	energieAct -= c;
	return energieAct;
}

int personnage::infligedegat(int d)
{
	vieAct -= d;
	if (vieAct < 0)
		vieAct = 0;
	return vieAct;
}


