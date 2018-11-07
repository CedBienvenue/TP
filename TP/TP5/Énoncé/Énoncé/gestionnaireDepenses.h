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
	/*vector<Depense*> getDepenses() const;
	int getNombreDepenses() const;
	int getIndexDe(Depense * depense) const;
	Depense* getDepenseParIndex(int i) const;*/
	double getTotalDepenses() const;

	//GestionnaireDepenses& ajouterDepense(Depense* depense);

private:
	//vector<Depense*> depenses_;
};

#endif // !GESTIONNAIREDEPENSE_H