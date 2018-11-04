/*
	Fichier : utilisateurPremium.cpp

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 4 novembre 2018
*/

/********************************************
* Titre: Travail pratique #4 - utilisateurPremium.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurPremium.h"

// Contructeurs
UtilisateurPremium::UtilisateurPremium(const string& nom, MethodePaiement methodePaiement,
	unsigned int joursRestants, const string& courriel, const string& idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), joursRestants_(joursRestants)
{}

// Methode d'acces
unsigned int UtilisateurPremium::getJoursRestants() const {
	return joursRestants_;
}

// Methode de modification
void UtilisateurPremium::setJoursRestants(unsigned int joursRestants) {
	joursRestants_ = joursRestants;
}

void UtilisateurPremium::print(ostream& os) const{
	os << "Utilisateur (Premium) " << getNom() << " :" << endl;
	os << "\t\t Total a payer: " << getTotalATransferer() << "$ (" <<
		(-1*getBalance()) << "$ economises)" << endl;
	os << "\t\t Jours restants: " << getJoursRestants() << endl;
}
