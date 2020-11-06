#include "ConfigFile.h"

ConfigFile::ConfigFile(Armurie* armo, CloneEnnemy* cl, std::string nom)
{
	fileLecture.open(nom.c_str());
	if (!fileLecture)
		std::cerr << "Erreur dans la lecture du fichier " + nom;
	armory = armo;
	clone = cl;
}

void ConfigFile::Lecturefichier()
{
	if (fileLecture)
	{
		std::string mot;
		while (std::getline(fileLecture,mot) ){
			if (mot == "arme")
				LectureArme();
			else if (mot == "armure")
				LectureArmure();
			else if (mot == "perso")
				LecturePerso();
			// lecture d'un commentaire.
			else if (mot == "#com")
			{
				do {
					fileLecture >> mot;
				} while (mot != "#fincom");

			}
			else
				std::cerr << "erreur dans la structure du fichier de config equipement et personnage";
		}
	}
}

void ConfigFile::LectureArme()
{
	int sagesse = 0, intelligence = 0, force = 0, dexterite = 0, agilite = 0;
	std::string mot;
	std::string nom;
	int prec=0;
	int degmagique[dmagiquetaille];
	int dephysique[dphysiquetaille];
	bool twohanded=false;

	do {
		fileLecture >> mot;
		if (mot == "sagesse")
			fileLecture >> sagesse;
		else if (mot == "intelligence")
			fileLecture >> intelligence;
		else if (mot == "force")
			fileLecture >> force;
		else if (mot == "dexterite")
			fileLecture >> dexterite;
		else if (mot == "agilite")
			fileLecture >> agilite;
		else if (mot == "precision")
			fileLecture >> prec;
		else if (mot == "nom")
			fileLecture >> nom;
		else if (mot == "degatphysique") {
			for (int k = 0; k < dphysiquetaille; k++)
				fileLecture >> dephysique[k];
		}
		else if (mot == "degatmagique") {
			for (int k = 0; k < dmagiquetaille; k++)
				fileLecture >> degmagique[k];
		}
		else if (mot == "twohanded") {
			std::string tmp;
			fileLecture >> tmp;
			if(tmp=="true")
				twohanded=true;
		}

	} while (mot != "####");
	armory->addArme(arme(caracteristique(force, sagesse, agilite, dexterite, intelligence), nom, degat(dephysique, degmagique), prec, twohanded));
}

void ConfigFile::LectureArmure()
{
	int sagesse = 0, intelligence = 0, force = 0, dexterite = 0, agilite = 0;
	std::string mot;
	std::string nom;
	int eva=0, armo=0;
	int res[dmagiquetaille];
	int typearmu=0;
	int emparmu=0;

	do {
		fileLecture >> mot;
		if (mot == "sagesse")
			fileLecture >> sagesse;
		else if (mot == "intelligence")
			fileLecture >> intelligence;
		else if (mot == "force")
			fileLecture >> force;
		else if (mot == "dexterite")
			fileLecture >> dexterite;
		else if (mot == "agilite")
			fileLecture >> agilite;
		else if (mot == "nom")
			fileLecture >> nom;
		else if (mot == "resistance") {
			for (int k = 0; k < dmagiquetaille; k++)
				fileLecture >> res[k];
		}
		else if (mot == "armure")
			fileLecture >> armo;
		else if (mot == "evasion")
			fileLecture >> eva;
		else if (mot == "typearmure")
			fileLecture >> typearmu;
		else if (mot == "emplacement")
			fileLecture >> emparmu;
	} while (mot != "####");
	armory->addArmure(armure(caracteristique(force, sagesse, agilite, dexterite, intelligence), nom, eva, armo, static_cast<classeArmure>(typearmu), static_cast<emplacementarmure>(emparmu), res));
}

void ConfigFile::LecturePerso()
{
	int sagesse=100, intelligence=100, force=100, dexterite=100, agilite=100;
	std::string mot;
	std::string nom;
	int vie=100;

	do {
		fileLecture >> mot;
		if (mot == "sagesse")
			fileLecture >> sagesse;
		else if (mot == "intelligence")
			fileLecture >> intelligence;
		else if (mot == "force")
			fileLecture >> force;
		else if (mot == "dexterite")
			fileLecture >> dexterite;
		else if (mot == "agilite")
			fileLecture >> agilite;
		else if (mot == "vie")
			fileLecture >> vie;
		else if (mot == "nom")
			fileLecture >> nom;

	} while (mot != "####");
	clone->addPerso(personnage(nom, vie, caracteristique(force, sagesse, agilite, dexterite, intelligence)));
	

}
