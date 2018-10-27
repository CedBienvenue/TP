/*
Fait par :  Cedrik Bienvenue (1894296)
Mohamed Khairallah Gharbi (1837067)
Date de derniere modification : 30 septembre 2018

*/
/********************************************
* Titre: Travail pratique #2 - utilisateur.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <vector>
#include "depense.h"

using namespace std;

class Utilisateur {
public:
	// Constructeurs
	Utilisateur();
	Utilisateur(const string& nom);
	//// TODO: Ajouter un constructeur par copie
	Utilisateur(const Utilisateur& nouveauUser);
	// Destructeur
	~Utilisateur();

	// Methodes d'accès
	string getNom() const;
	Depense* getDepense(int index) const;
	unsigned int getNombreDepense() const;
	double getTotalDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);
	//Depense(const Depense* depense);

	//// TODO: Ajouter un operateur += et =
	Utilisateur& operator+=(Depense* depense);
	Utilisateur& operator=(const Utilisateur& nouveauUser);
	
	//// TODO: Remplacer par une surcharge de l'operateur <<
	friend ostream& operator<<(ostream&, const Utilisateur&);

private:
	string nom_;
	//// TODO: Remplacer depenses_ par un vecteur
	vector<Depense*> depenses_;

};
#endif