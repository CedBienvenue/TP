/*
Fait par :  Cedrik Bienvenue (1894296)
Mohamed Khairallah Gharbi (1837067)
Date de derniere modification : 30 septembre 2018

*/
/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "utilisateur.h"
#include <ostream>
// Constructeurs
Utilisateur::Utilisateur() : nom_(""){
}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom) {
}

Utilisateur::Utilisateur(const Utilisateur& nouveauUser): nom_(nouveauUser.nom_), 
depenses_(nouveauUser.depenses_) { 
}

//Destructeur
Utilisateur::~Utilisateur() {
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const {
	return depenses_.size();
}

double Utilisateur::getTotalDepenses() const {
	double total = 0;
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

Depense* Utilisateur::getDepense(int index) const {
	if (index >= 0 && index < depenses_.size())
	{
		return depenses_[index];
	}
}

// Methodes d'ajout
Utilisateur& Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
	return *this;
}


Utilisateur& Utilisateur::operator=(const Utilisateur& nouveauUser) {
	if (this != &nouveauUser)
	{
		nom_ = nouveauUser.nom_;
		depenses_ = nouveauUser.depenses_;
	}
	return *this;
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

// Methode d'affichage

ostream& operator<<(ostream& output, const Utilisateur& u) {
	output << "Utilisateur : " << u.getNom() << " a depense pour un total de : " << u.getTotalDepenses() << endl;
	cout << "\t Liste de depenses : " << endl;
	for (unsigned int i = 0; i < u.getNombreDepense(); i++)
	{
		output << "\t\t";
		output << *u.depenses_[i];
	}
	return output;
}