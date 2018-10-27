/*	Fichier : utilisateurPremium.cpp

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification :21 Octobre 2018

*/
#include "utilisateurPremium.h"

//Constructeurs : 
UtilisateurPremium::UtilisateurPremium(const string& nom) : Utilisateur(nom, Premium), joursRestants_(30), taux_(TAUX_REGULIER) {

}

UtilisateurPremium::UtilisateurPremium(const Utilisateur& utilisateur) : Utilisateur(utilisateur){
	
}


// Méthodes d'accès
unsigned int UtilisateurPremium::getJoursRestants() const {
	return joursRestants_;
}

double UtilisateurPremium::getTaux() const {
	return taux_; 
}


// Méthodes de modification
void UtilisateurPremium::setJoursRestants(unsigned int joursRestants) {
	joursRestants_ = joursRestants; 
}

string UtilisateurPremium::getNom() const {
	return Utilisateur::getNom();
}

double UtilisateurPremium::getTotalDepenses() const {
	return Utilisateur::getTotalDepenses();
}

TypeUtilisateur UtilisateurPremium::getType() const {
	return Utilisateur::getType();
}

double UtilisateurPremium::getInteret() const {
	return Utilisateur::getInteret();
}

unsigned int UtilisateurPremium::getNombreDepenses() const {

	return Utilisateur::getNombreDepenses();
}

vector <Depense*> UtilisateurPremium::getDepenses() const {
	return Utilisateur::getDepenses();
}
//Méthode de calcul 
void UtilisateurPremium::calculerTaux() {
	unsigned count = 0; 
	for (unsigned int i = 0 ; i < getNombreDepenses() ; i++) {
		count++;
		if (count % 2 == 0) {
			taux_ -= 0.01; 
		}	
	}
}

//Operateurs
UtilisateurPremium& UtilisateurPremium::operator= (Utilisateur* utilisateur) {
	if (this != utilisateur) {
		Utilisateur::operator=(utilisateur);
	}
	return *this;
}

ostream& operator << (ostream& os, const UtilisateurPremium& utilisateur) {
	os << "( Taux final de " << utilisateur.getTaux() * 100 << " % )" << endl;
	return os;
}
