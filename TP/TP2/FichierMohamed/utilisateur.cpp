/*
	Fait par :  Cedrik Bienvenue ()
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 30 septembre 2018

*/
/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : nom_(""), depenses_({}) {
}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom), depenses_({}) {
}
//Constructeur de copie : 
Utilisateur::Utilisateur(const Utilisateur& nouveauUser): nom_(nouveauUser.nom_), 
depenses_({}) {
	depenses_ = nouveauUser.depenses_ ; 
}

//Destructeur
Utilisateur::~Utilisateur() {
	depenses_.clear(); 
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

vector <Depense*> Utilisateur::getDepense() const {
	return depenses_; 
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

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}
//Methode d'ajout 

void Utilisateur::ajouterDepense(Depense* depense) {
	depenses_.push_back(depense);
}

//Surcharge d'operateur : 
Utilisateur& Utilisateur::operator+=(Depense* depense) {
	ajouterDepense(depense);
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



// Methode d'affichage

ostream& operator<<(ostream& output, const Utilisateur& utilisateur) {
	output << "Utilisateur : " << utilisateur.getNom() << " a depense pour un total de : " << utilisateur.getTotalDepenses() << endl;
	cout << "\t Liste de depenses : " << endl;
	for (unsigned int i = 0; i < utilisateur.getNombreDepense(); i++)
	{
		output << "\t\t";
		output << (*utilisateur.getDepense()[i]);
	}

	return output;
}