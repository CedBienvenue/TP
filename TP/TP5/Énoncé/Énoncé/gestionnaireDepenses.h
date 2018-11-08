#pragma once

#ifndef GESTIONNAIREDEPENSE_H
#define GESTIONNAIREDEPENSE_H

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"

#include <algorithm>
#include <vector>
using namespace std;

class GestionnaireDepenses : public GestionnaireGenerique<Depense*, vector<Depense*>, Depense*, AjouterDepense> {
public:
	double getTotalDepenses() const;
};

#endif // !GESTIONNAIREDEPENSE_H