/*	Fichier : utilisateurRegulier.cpp

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification :21 Octobre 2018

*/
#include "utilisateurRegulier.h"

//Constructeurs : 

UtilisateurRegulier::UtilisateurRegulier(const string& nom) : Utilisateur(nom, Regulier), estGroupe_(false) {
	interet_ = 0; 
}

UtilisateurRegulier::UtilisateurRegulier(const Utilisateur& utilisateur) : Utilisateur(utilisateur){
}


//Méthodes d'accès

bool UtilisateurRegulier::estGroupe() const {
	return estGroupe_; 
}

string UtilisateurRegulier::getNom() const {
	return Utilisateur::getNom();
}

double UtilisateurRegulier::getTotalDepenses() const {
	return Utilisateur::getTotalDepenses();
}

TypeUtilisateur UtilisateurRegulier::getType() const {
	return Utilisateur::getType();
}

double UtilisateurRegulier::getInteret() const {
	return Utilisateur::getInteret();
}

unsigned int UtilisateurRegulier::getNombreDepenses() const {

	return Utilisateur::getDepenses().size();
}

vector <Depense*> UtilisateurRegulier::getDepenses() const {
	return Utilisateur::getDepenses();
}

//Méthodes de modification
void UtilisateurRegulier::setEtatGroupe(bool etat) {
	estGroupe_ = etat; 
}


//Surcharge d'operateur : 
UtilisateurRegulier& UtilisateurRegulier::operator=(Utilisateur* utilisateur) {
	if (this != &utilisateur) {
		Utilisateur::operator=(utilisateur);
	}
	return *this;
}

// Methode d'affichage

ostream& operator<<(ostream& os, const UtilisateurRegulier& utilisateur) {
	return os;
}