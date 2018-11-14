/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#ifndef GESTIONNAIREUTILISATEURS_H
#define GESTIONNAIREUTILISATEURS_H


#pragma once

#include "utilisateur.h"
#include "gestionnaireGenerique.h"
#include "foncteur.h"

#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

class GestionnaireUtilisateurs : public GestionnaireGenerique<Utilisateur*, map<Utilisateur*, double>, pair<Utilisateur*, double>, AjouterUtilisateur> {
public:
	
	void mettreAJourComptes(Utilisateur* payePar, double montant) const;
	bool estExistant(Utilisateur* utilisateur) const;

	// Methode d'acces
	vector<double> getComptes() const;

	pair<Utilisateur*, double>& getMax() const;
	pair<Utilisateur*, double>& getMin() const;

	Utilisateur* getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const;

	vector<pair<Utilisateur*, double>> getUtilisateursEntre(double borneInf, double borneSup) const;

	// Methode de modification
	GestionnaireUtilisateurs& setCompte(pair<Utilisateur*, double> p);
};

#endif // !GESTIONNAIREUTILISATEURS_H