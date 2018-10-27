/*
	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 30 septembre 2018

*/
/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "depense.h"

// Constucteurs
Depense::Depense() : nom_(""), montant_(0),lieu_(nullptr) {
}

Depense::Depense(const string& nom, double montant, const string& lieu) : nom_(nom), montant_(montant),lieu_(nullptr) {
	lieu_ = new string(lieu); 
}

Depense::Depense(const Depense& depense) : nom_(depense.nom_), montant_(depense.montant_) , lieu_(nullptr) {
	lieu_ = new string(*(depense.lieu_)); 
}


Depense::~Depense() {
	delete lieu_;
}
// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

string* Depense::getLieu() const {
	return lieu_; 
}
// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(const string& lieu) {
	delete lieu_; 
	lieu_ = new string(lieu); 
}
//Surcharge de l'operateur=
Depense& Depense::operator=(const Depense& depense )  {
	if ( this != &depense) {
		delete lieu_; 
		lieu_ = new string(*(depense.lieu_));
		nom_ = depense.nom_ ; 
		montant_ = depense.montant_; 
	}
	return *this ; 
}

// Methode d'affichage
ostream& operator<< (ostream& output, const Depense& depense)  {
	output << "Achat : " << depense.getNom() << " Prix : " << depense.getMontant() << " ; " << endl; 
	return output; 
}
