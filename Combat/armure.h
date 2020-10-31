#pragma once
#include "equipement.h"
#include "degat.h"
#include <string>
enum class emplacementarmure { chest, leg, head, hand };
const int emplacementarmuretaille = 4;

class armure :public equipement
{
private : 
    int evasion, armor;
    int resistance[dmagiquetaille];
    classeArmure typeArmure;
    emplacementarmure emplacement;
public : 
    //les deux constructeur initiliase la liste de resistance à 0
    armure();     
    armure(caracteristique, std::string, int, int, classeArmure,emplacementarmure);
    //constructeur avec liste de resistance
    armure(caracteristique, std::string, int eva, int armor, classeArmure, emplacementarmure, int res[dmagiquetaille]);

    void setResistance(dmagique, int);
    int getEvasion() const;
    int getArmure() const; 
    int getResistance(dmagique) const;
    emplacementarmure getEmplacement() const;
    classeArmure getTypeArmure() const; 
};

