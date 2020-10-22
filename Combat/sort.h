#pragma once
#include "abilite.h"
class sort :
    public abilite
{
public : 
    float chanceToucher(personnage const& lanceur, personnage const& cible) const;
    int degatinflige(personnage const& lanceur, personnage const& cible) const;
    bool utiliser(personnage lanceur, personnage cible);
};

