#pragma once
#include "equipement.h"
#include "degat.h"
#include <string>

class arme :
    public equipement
{
private :
    degat degatarme;
    int precision;
    bool twohanded;
public: 

    arme();
    arme(caracteristique c, std::string n,degat d, int precis, bool twohan);
 
    degat getdegat() const ;
    int getprecision() const;
    bool istwohanded() const;

};

