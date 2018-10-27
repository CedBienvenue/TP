/*	Fichier : utilisateur.h

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification :21 Octobre 2018

*/
/********************************************
* Titre: Travail pratique #3 - utilisateur.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <string>
#include <iostream>
#include <vector>
#include"depenseGroupe.h"
#include"depense.h"

const double TAUX_REGULIER = 0.05;

enum TypeUtilisateur{Regulier, Premium};

using namespace std;

class Utilisateur {
public:
	// Constructeurs
	Utilisateur();
	Utilisateur(const string& nom = "", TypeUtilisateur type = Regulier);
	Utilisateur(const Utilisateur& utilisateur);

	//destructeur 
	~Utilisateur(); 

	// Methodes d'accès
	virtual string getNom() const;
	virtual double getInteret() const;
	virtual double getTotalDepenses() const;
	virtual TypeUtilisateur getType() const;
	virtual vector<Depense*> getDepenses() const;
	virtual unsigned int getNombreDepenses() const;

	// Methodes de modification
	void setNom(const string& nom);
	void setType(const TypeUtilisateur type);
	void ajouterInteret(double montant);
	void calculerTotalDepenses();
	
	

	Utilisateur& operator+=(Depense* depense);
	virtual Utilisateur& operator=(Utilisateur* utilisateur);
	
	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Utilisateur& user);


protected:
	double interet_;
	string nom_;
	TypeUtilisateur type_; 
	vector <Depense*> depenses_;
	double totalDepense_; 
};
#endif