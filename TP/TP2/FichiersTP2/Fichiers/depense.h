/*
Fait par :  Cedrik Bienvenue (1894296)
Mohamed Khairallah Gharbi (1837067)
Date de derniere modification : 30 septembre 2018

*/
/********************************************
* Titre: Travail pratique #2 - depense.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#ifndef DEPENSE_H
#define DEPENSE_H
#include <string>
#include <iostream>

using namespace std;

class Depense {
public:
	// Constructeurs
	// TODO: Ajouter le attribut objet dans les constructeurs
	Depense();
	Depense(const string& nom, double montant, const string& lieu);

	~Depense();

	// TODO: Ajouter un constructeur par copie
	Depense (const Depense& depense); 
	// Methodes d'acces
	string getNom() const;
	double getMontant() const;
	string* getLieu() const;

	// Methodes de modifications
	void setNom(const string& nom);
	void setMontant(double montant);
	void setLieu(const string& lieu);

	// TODO: Ajouter une surcharge de l'operateur =
	Depense& operator=(const Depense& depense);
	// TODO: Remplacer par une surcharge de l'operateur <<
	friend ostream& operator<<(ostream& output, const Depense&); 

private:
	string nom_;
	double montant_;
	string* lieu_;// TODO: Ajouter l'attribut lieu
};
#endif