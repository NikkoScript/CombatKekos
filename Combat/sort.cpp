#include "sort.h"
#include "coefDegPhys.h"
#include "RNGClasse.h"
float sort::chanceToucher(personnage const& lanceur, personnage const& cible) const
{
	int precision = lanceur.getcarac().getCarac(carac::sagesse) ;
	float proba = (precision / (precision + 20.0f));
	return proba;
}

int sort::degatinflige(personnage const& lanceur, personnage const& cible) const
{
	coefDegPhys coef(cible.getInv().getClasseArmure(), cible.getInv().getSumResistance(), cible.getInv().getSumArmor());
	int intelligence = lanceur.getcarac().getCarac(carac::intelligence);
	float bonusMagique = 1.0f;
	bonusMagique += (intelligence - 100.0f) / (intelligence + 100.0f);
	degat degatMagique(deg);
	int resultat = coef.multDeg(degatMagique.multmagique(bonusMagique));
	return resultat;
}

bool sort::utiliser(personnage lanceur, personnage cible)
{
	float touche = chanceToucher(lanceur, cible);
	RNGClasse* alea = new RNGClasse();
	//condition : echec de l'attaque? 
	lanceur.consume(consume);
	lastuse = cooldown;
	if (touche < alea->getfloat())
		return false;
	cible.infligedegat(degatinflige(lanceur, cible));
	return true;
}
