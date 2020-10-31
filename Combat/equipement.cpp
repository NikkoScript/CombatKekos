#include "equipement.h"

equipement::equipement() : stat(), duramax(100), duraact(100), nom("none"), type(typeequipement::armure)
{
}

equipement::equipement(caracteristique c, std::string n) : stat(c), duramax(100), duraact(100),nom(n), type(typeequipement::armure)
{
}

equipement::equipement(caracteristique c, std::string n, typeequipement t) : equipement(c,n)
{
	type = t;
}

equipement::~equipement()
{
}


int equipement::reparer(int c)
{
	duraact += c;
	if (duraact > duramax)
		duraact = duramax;
	return duraact;
}

bool equipement::isBreakable() const
{
	if (duraact == 0)
		return true;
	return false;
}

int equipement::useDura(int i)
{
	duraact -= i;
	if (duraact < 0)
		duraact = 0;
	return duraact;
}

typeequipement equipement::gettype()
{
	return type;
}

std::string equipement::getNom() const
{
	return nom;
}

bool equipement::isequal(std::string value)
{
	if (nom == value)
		return true;
	return false;
}

bool equipement::isEquipable(caracteristique c) const
{
	return stat.greaterthan(c);
}

bool operator==(equipement e, std::string v)
{
	return e.isequal(v);
}
