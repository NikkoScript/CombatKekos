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
    arme(caracteristique, std::string,degat, int, bool);
 
    degat getdegat() const ;
    int getprecision() const;
    bool istwohanded() const;

};

