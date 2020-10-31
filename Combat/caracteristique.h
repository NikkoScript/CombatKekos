#pragma once

enum class carac{ force, sagesse, agilite, dexterite, intelligence };
class caracteristique
{
private :
	int stat[5];
	// variable pour les différents bonus en combat .
	int statBonus[5];
	int attribution;
	
public:
	caracteristique();
	// constructeur avec carac perso ( pour equipement ou personnage avec stat non par defaut ) 
	caracteristique(int f, int s, int a, int d, int i);
	// constructeur avec point d'attribution perso ( 10 par niveau)
	caracteristique(int);
	// améliore la stat en paramètre si il reste des point d'attribution retourne la résuiite de l'incrément 
	bool incrementCarac(carac);
	int getCarac(carac) const;
	int getAttribution() const;
	int getCaracBase(carac) const;
	int getCaracBonus(carac) const;
	void setstatBonus(carac, int);
	//ajoute 10 point d'attribution
	void levelup();

	// verifie que l'equipement this est equipable avec le jeu de valeur entrée en paramètre ( toutes les carac de l'equipement >= valeur ) 
	bool greaterthan(caracteristique const&) const;

};

