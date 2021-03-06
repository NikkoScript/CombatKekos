#include "degat.h"

degat::degat()
{
	for (int k = 0; k < dphysiquetaille; k++) {
		degatphysique[k] = 0;
	}
	for (int k = 0; k < dmagiquetaille; k++) {
		degatmagique[k] = 0;
	}
}

degat::degat(int perf, int impact, int tranchant)
{
	for (int k = 0; k < dmagiquetaille; k++) {
		degatmagique[k] = 0;
	}
	degatphysique[0] = perf;
	degatphysique[1] = impact;
	degatphysique[2] = tranchant;
}

degat::degat(int feu , int eau, int terre, int vent, int ombre, int lumiere)
{
	for (int k = 0; k < dphysiquetaille; k++) {
		degatphysique[k] = 0;
	}
	degatmagique[0] = feu;
	degatmagique[1] = eau;
	degatmagique[2] = terre;
	degatmagique[3] = vent;
	degatmagique[4] = ombre;
	degatmagique[5] = lumiere;


}

degat::degat(int perf, int impact, int tranchant, int feu, int eau, int terre, int vent, int ombre, int lumiere)
{
	degatphysique[0] = perf;
	degatphysique[1] = impact;
	degatphysique[2] = tranchant;
	degatmagique[0] = feu;
	degatmagique[1] = eau;
	degatmagique[2] = terre;
	degatmagique[3] = vent;
	degatmagique[4] = ombre;
	degatmagique[5] = lumiere;
}

degat::degat(int dgp[dphysiquetaille], int dgm[dmagiquetaille] )
{
	for (int k = 0; k < dphysiquetaille; k++)
		degatphysique[k] = dgp[k];
	for (int j = 0; j < dmagiquetaille; j++)
		degatmagique[j] = dgm[j];
}


int degat::getdegatphysique(dphysique d) const
{
	return degatphysique[static_cast<int>(d)];
}

int degat::getdegatmagique(dmagique d) const
{
	return degatmagique[static_cast<int>(d)];
}

degat& degat::adddegat(degat const& b)
{
	//ajout physique
	for (int k = 0; k < dphysiquetaille;	k++) {
		degatphysique[k] += b.degatphysique[k];
	}

	//ajout magique
	for (int j = 0; j < dmagiquetaille; j++) {
		degatmagique[j] += b.degatmagique[j];
	}

	return *this;
}

degat degat::multphysique(float value)
{
	for (int k = 0; k < dphysiquetaille; k++) {
		degatphysique[k] = value * degatphysique[k];
	}
	return *this;
}

degat degat::multmagique(float value)
{
	for (int k = 0; k < dmagiquetaille; k++) {
		degatmagique[k] = value * degatmagique[k];
	}
	return *this;
}

degat& degat::operator+=(degat const& a)
{
	this->adddegat(a);
	return *this ;
}

std::string degat::phyisqueToString(dphysique d)
{
	std::string res="";
	switch (d)
	{
	case dphysique::perforant:
		res="per";
		break;
	case dphysique::impact:
		res = "imp";
		break;
	case dphysique::tranchant:
		res = "tra";
		break;
	default:
		break;
	}
	return res;
}

std::string degat::magiqueToString(dmagique d)
{
	std::string res = "";
	switch (d)
	{
	case dmagique::feu:
		res = "feu";
		break;
	case dmagique::eau:
		res = "eau";
		break;
	case dmagique::terre:
		res = "ter";
		break;
	case dmagique::vent:
		res = "ven";
		break;
	case dmagique::ombre:
		res = "omb";
		break;
	case dmagique::lumiere:
		res = "lum";
		break;
	default:
		break;
	}
	return res;
}

degat operator+(degat const& a , degat const& b )
{
	degat copie(a);
	copie += b;
	return copie;
}
