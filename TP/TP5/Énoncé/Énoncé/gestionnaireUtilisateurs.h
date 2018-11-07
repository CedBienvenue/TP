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
#include <vector>

using namespace std;

class GestionnaireUtilisateurs : public GestionnaireGenerique<Utilisateur*, map<Utilisateur*, double>, Utilisateur*, AjouterUtilisateur> {
public:
	/*Utilisateur* getUtilisateurParIndex(int i) const;
	vector<Utilisateur*> getUtilisateurs() const;*/
	vector<double> getComptes() const;
	void mettreAJourComptes(Utilisateur* payePar, double montant) const;
	
	pair<Utilisateur*, double>& getMax() const;
	pair<Utilisateur*, double>& getMin() const;

	Utilisateur* getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const;

	vector<pair<Utilisateur*, double>> getUtilisateursEntre(double borneInf, double borneSup) const;

	GestionnaireUtilisateurs& setCompte(pair<Utilisateur*, double> p);
	/*int getNombreUtilisateurs() const;
	int getIndexDe(Utilisateur* utilisateur) const;*/

	
	//GestionnaireUtilisateurs& ajouterUtilisateur(Utilisateur* utilisateur);

private:
	//vector<Utilisateur*> utilisateurs_;
};

#endif // !GESTIONNAIREUTILISATEURS_H