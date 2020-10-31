#include "sacInventaire.h"

std::vector<arme*> sacInventaire::getListArme() const
{
    std::vector<arme*> res;
    for (int k = 0; k < equipSac.size(); k++)
        if (equipSac[k]->gettype() == typeequipement::arme)
            res.push_back((arme*)equipSac[k]);
    return res;
    
}

std::vector<armure*> sacInventaire::getListArmure() const
{
    std::vector<armure*> res;
    for (int k = 0; k < equipSac.size(); k++)
        if (equipSac[k]->gettype() == typeequipement::armure)
            res.push_back((armure*)equipSac[k]);
    return res;
}

// recherche l'equipement dans le sac est l'equipe sur le personnage retourne le boolean correspondant a la rrésusite de l'opération ( ajout si trouvé sinon RAF ) 

 bool sacInventaire::equiper(equipement* e, personnage* p)
{
    if (e->isEquipable(p->getcarac()))
    {
        // recherche de l'indice correspondant a l'equipemeent entrée en paramêtre
        for (int k = 0; k < equipSac.size(); k++)
        {
            if (equipSac[k] == e)
            {
                p->getInv().setEquipement(e);
                equipBy[k] = p;
                return true;
            }
        }
    }
    return false;
}

bool sacInventaire::addequipement(equipement* e)
{
    //recherche si l'élément est déja présent.
    for (int k = 0; k < equipSac.size(); k++)
        if (equipSac[k] == e)
            return false;
    // si non trouvé on l'ajoute a la fin , il ets attaché icii à aucun personnage.
    equipSac.push_back(e);
    equipBy.push_back(nullptr);
    return true;
}

