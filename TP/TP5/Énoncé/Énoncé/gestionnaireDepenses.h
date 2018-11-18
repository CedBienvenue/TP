/********************************************
*
* Titre: Travail pratique #5 - gestionnaireDepenses.h
* Date: 18 Novembre 2018
* Auteur: C�drik Bienvenue (1894296) & Mohamed Khairallah Gharbi (1837067)
*
*******************************************/
#pragma once

#ifndef GESTIONNAIREDEPENSE_H
#define GESTIONNAIREDEPENSE_H

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"
#include "foncteur.h"

#include <algorithm>
#include <vector>
using namespace std;

class GestionnaireDepenses : public GestionnaireGenerique<Depense*, vector<Depense*>, Depense*, AjouterDepense> {
public:
	double getTotalDepenses() const;
};

#endif // !GESTIONNAIREDEPENSE_H