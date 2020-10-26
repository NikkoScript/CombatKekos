#include "abilite.h"
#include "RNGClasse.h"
#include "coefDegPhys.h"
#include <iostream>

abilite::abilite() : deg(), nom("attaque"), consume(10), cooldown(1), bonus(1), lastuse(0)
{
}

abilite::abilite(degat d, std::string n, int cons, int cd,float b) : deg(d), nom(n), consume(cons),cooldown(cd),bonus(b),lastuse(0)
{
}

bool abilite::coolDown() const
{
	if(lastuse>0)
		return false;
	return true;
}

void abilite::decrLastUse()
{
	if (lastuse > 0)
		lastuse--;
}

float abilite::chanceToucher(personnage const& lanceur, personnage const& cible) const
{
	int precision = lanceur.getcarac().getCarac(carac::dexterite) + lanceur.getInv().getPrecision();
	int evasion = cible.getcarac().getCarac(carac::agilite) + cible.getInv().gettSumEva();
	float proba = -((evasion - 100.0f) / (evasion + 100.0f)) + (precision / (precision + 20.0f));
	return proba;
}

int abilite::degatinflige(personnage const& lanceur, personnage const& cible) const
{
	coefDegPhys coef(cible.getInv().getClasseArmure(), cible.getInv().getSumResistance(), cible.getInv().getSumArmor());
	int force = lanceur.getcarac().getCarac(carac::force);
	float bonusPhysique = 1.0f;
	bonusPhysique += (force - 100.0f) / (force + 100.0f);
	int intelligence = lanceur.getcarac().getCarac(carac::intelligence);
	float bonusMagique = 1.0f;
	bonusMagique += (intelligence - 100.0f) / (intelligence + 100.0f);
	degat degatMagique(deg);
	degat degatPhysique(lanceur.getInv().getDegat());
	int resultat = coef.multDeg(degatMagique.multmagique(bonusMagique) + degatPhysique.multphysique(bonusPhysique)); 
	return resultat;
}

bool abilite::utiliser(personnage *lanceur, personnage *cible)
{
	float touche = chanceToucher(*lanceur, *cible);
	RNGClasse* alea = new RNGClasse();
	//condition : echec de l'attaque? 
	lanceur->consume(consume);
	lastuse = cooldown;
	if (touche < alea->getfloat()) {
		std::cout << "l'attaque " + nom + " a échoué";
		return false;
	}
	int deg = degatinflige(*lanceur,* cible);
	std::cout << lanceur->getNom() + " utilise " + nom + " et a infligé " + std::to_string(deg) + " dégat  à " + cible->getNom();
	cible->infligedegat(deg);
	return true;
}

bool abilite::isequal(std::string value)
{
	if (nom == value)
		return true;
	return false;
}

bool operator==(abilite ab, std::string n)
{
	return ab.isequal(n);
}
