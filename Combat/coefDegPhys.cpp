#include "coefDegPhys.h"

coefDegPhys::coefDegPhys(classeArmure c,int *res, int armure)
{
	coef = new float[dphysiquetaille];
	resmagique = new float[dmagiquetaille];
	for (int k = 0; k < dmagiquetaille; k++) {
		resmagique[k] =1.0f-( res[k] / (res[k] + 100.0f));
	}
	for (int j = 0; j < dphysiquetaille; j++)
	{
		coef[j] = 1.0f - (armure / (armure + 300.0f));
	}
	switch (c)
	{
	case classeArmure::lourde:
		coef[static_cast<int>(dphysique::perforant)] *= 0.9f;
		coef[static_cast<int>(dphysique::impact)] *= 1.0f;
		coef[static_cast<int>(dphysique::tranchant)] *= 0.8f;
		break;
	case classeArmure::moyenne:
		coef[static_cast<int>(dphysique::perforant)] *= 1.1f;
		coef[static_cast<int>(dphysique::impact)] *= 0.9f;
		coef[static_cast<int>(dphysique::tranchant)] *= 1.0f;
		break;
	case classeArmure::legere:
		coef[static_cast<int>(dphysique::perforant)] *= 1.1f;
		coef[static_cast<int>(dphysique::impact)] *= 1.0f;
		coef[static_cast<int>(dphysique::tranchant)] *= 1.2f;
		break;
	default:
		break;
	}
}

float* coefDegPhys::getcoef() const
{
	return coef;
}

float coefDegPhys::multDeg(degat d)
{
	float resultat = 0.0f;
	resultat += coef[static_cast<int>(dphysique::perforant)] * d.getdegatphysique(dphysique::perforant);
	resultat += coef[static_cast<int>(dphysique::impact)] * d.getdegatphysique(dphysique::impact);
	resultat += coef[static_cast<int>(dphysique::tranchant)] * d.getdegatphysique(dphysique::tranchant);
	resultat += resmagique[static_cast<int>(dmagique::feu)] * d.getdegatmagique(dmagique::feu);
	resultat += resmagique[static_cast<int>(dmagique::eau)] * d.getdegatmagique(dmagique::eau);
	resultat += resmagique[static_cast<int>(dmagique::terre)] * d.getdegatmagique(dmagique::terre);
	resultat += resmagique[static_cast<int>(dmagique::vent)] * d.getdegatmagique(dmagique::vent);
	resultat += resmagique[static_cast<int>(dmagique::ombre)] * d.getdegatmagique(dmagique::ombre);
	resultat += resmagique[static_cast<int>(dmagique::lumiere)] * d.getdegatmagique(dmagique::lumiere);

	return resultat;
}
