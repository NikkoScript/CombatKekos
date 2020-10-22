#include "armure.h"


armure::armure() : equipement() , evasion(0), armor(0),typeArmure(classeArmure::legere),emplacement(emplacementarmure::chest)
{
	for (int k = 0; k < dmagiquetaille; k++)
		resistance[k] = 0;
}

armure::armure(caracteristique c, std::string n, int e, int a, classeArmure t,emplacementarmure emp) :equipement(c,n), evasion(e),armor(a),typeArmure(t),emplacement(emp)
{
	for (int k = 0; k < dmagiquetaille; k++)
		resistance[k] = 0;
}


void armure::setResistance(dmagique d, int v)
{
	resistance[static_cast<int>(d)] = v;
}

int armure::getEvasion() const
{
	return evasion;
}

int armure::getArmure() const
{
	return armor;
}

int armure::getResistance(dmagique d) const
{
	return resistance[static_cast<int>(d)];
}

emplacementarmure armure::getEmplacement() const
{
	return emplacement;
}

classeArmure armure::getTypeArmure() const
{
	return typeArmure;
}
