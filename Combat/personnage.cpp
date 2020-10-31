#include "personnage.h"

personnage::personnage() : carac(),vieMax(100),vieAct(100),energieAct(100),energieMax(100),nom("")
{
}

personnage::personnage(std::string n) :  carac(), vieMax(100), vieAct(100), energieAct(100), energieMax(100), nom(n)
{
}

personnage::personnage(std::string name, int hpmax, caracteristique c) : carac(c), vieAct(hpmax), vieMax(hpmax), energieAct(100), energieMax(100), nom(name)
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

bool personnage::isequal(std::string value) const
{
	if (nom == value)
		return true;
	return false;
}

int personnage::infligedegat(int d)
{
	vieAct -= d;
	if (vieAct < 0)
		vieAct = 0;
	return vieAct;
}

bool operator==(personnage perso, std::string value)
{
	return perso.isequal(value);
}
