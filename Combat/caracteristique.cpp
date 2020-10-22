#include "caracteristique.h"

caracteristique::caracteristique()
{
	for (int k=0; k < 5; k++) {
		stat[k] = 100;
		statBonus[k] = 0;
	}
	attribution = 0;
}

caracteristique::caracteristique(int f, int s , int a, int d, int i)
{
	for (int k = 0; k < 5; k++) {
		statBonus[k] = 0;
	}
	stat[static_cast<int>(carac::agilite)] = a;
	stat[static_cast<int>(carac::sagesse)] = s;
	stat[static_cast<int>(carac::force)] = f;
	stat[static_cast<int>(carac::dexterite)] = d;
	stat[static_cast<int>(carac::intelligence)] = i;

	attribution = 0;

}


caracteristique::caracteristique(int lvl)
{
	caracteristique();
	attribution = lvl * 10;
}

bool caracteristique::incrementCarac(carac c)
{	
	if (attribution > 0) {
		stat[static_cast<int>(c)]++;
		attribution--;
		return true;
	}
	else
	{
		return false;
	}
	
}

int caracteristique::getCarac(carac c) const
{
	return stat[static_cast<int>(c)] + statBonus[static_cast<int>(c)];
}

int caracteristique::getAttribution() const
{
	return attribution;
}

int caracteristique::getCaracBase(carac c) const
{
	return stat[static_cast<int>(c)];
}

int caracteristique::getCaracBonus(carac c) const
{
	return statBonus[static_cast<int>(c)];
}

void caracteristique::setstatBonus(carac c,int i)
{
	statBonus[static_cast<int>(c)] = i;
}

void caracteristique::levelup()
{
	attribution += 10;
}

bool caracteristique::greaterthan(caracteristique const& val) const
{
	for (int k = 0; k < 5; k++) {
		if (stat[k] < val.stat[k])
			return false;

	}
	return true;
}
