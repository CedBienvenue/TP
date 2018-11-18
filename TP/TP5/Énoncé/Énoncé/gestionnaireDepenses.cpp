/********************************************
*
* Titre: Travail pratique #5 - gestionnaireDepenses.cpp
* Date: 18 Novembre 2018
* Auteur: Cédrik Bienvenue (1894296) & Mohamed Khairallah Gharbi (1837067)
*
*******************************************/
#include "gestionnaireDepenses.h"

#include <algorithm>
#include <functional>

// Methode qui retourne le montant total depense par le groupe.
double GestionnaireDepenses::getTotalDepenses() const
{
	double totalDepense = 0.0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); ++it)
	{
		totalDepense += (*it)->getMontant();
	}
	return totalDepense;

}