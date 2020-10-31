#include "arme.h"

arme::arme() : degatarme(), precision(0), twohanded(false)
{
}

arme::arme(caracteristique c, std::string n, degat d, int p, bool t) : equipement(c,n,typeequipement::arme), degatarme(d), precision(p), twohanded(t)
{
}

degat arme::getdegat() const
{
    return degatarme;
}

int arme::getprecision() const
{
    return precision;
}

bool arme::istwohanded() const
{
    return twohanded;
}
