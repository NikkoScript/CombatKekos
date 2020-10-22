#include "equipement.h"

equipement::equipement() : stat(),duramax(100),duraact(100),nom("none")
{
}

equipement::equipement(caracteristique c, std::string n) : stat(c), duramax(100), duraact(100),nom(n)
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

std::string equipement::getNom() const
{
	return nom;
}

bool equipement::isEquipable(caracteristique c) const
{
	return stat.greaterthan(c);
}
