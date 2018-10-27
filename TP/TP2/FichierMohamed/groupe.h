/*
	Fait par :  Cedrik Bienvenue ()
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 30 septembre 2018

*/
/********************************************
* Titre: Travail pratique #2 - groupe.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include "transfert.h"
#include<vector>

using namespace std;

class Groupe {
public:
	// Constructeurs
	Groupe();
	Groupe(const string& nom);

	// Destructeur
	~Groupe();

	// Methodes d'acces
	string getNom() const;
	unsigned int getNombreDepenses() const;
	double getTotalDepenses() const;
	unsigned int getNombreTransfert() const; 
	// Methodes de modification
	void setNom(const string& nom);

	// Methodes d'ajout
	// TODO: Modifier pour utiliser la surcharge d'operateur
	//Methode d'ajout de depense : 
	Groupe& ajouterDepense(Depense* depense, Utilisateur* utilisateur);
	// Methode d'ajout d'utilisateur :
	Groupe& operator+=(Utilisateur *utilisateur);


	// Methodes de calcul
	void calculerComptes();
	void equilibrerComptes();

	// TODO: Remplacer par une surcharge de l'operateur <<
	friend ostream& operator<< (ostream& output, const Groupe*); 

private:
	string nom_;
	// Remplacer les doubles pointeurs par des vecteurs
	vector <Utilisateur*> utilisateurs_;
	vector <Depense*> depenses_;
	vector <Transfert*> transferts_;
	vector <double> comptes_;

};

#endif
