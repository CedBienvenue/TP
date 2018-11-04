/*
	Fichier : utilisateurRegulier.cpp

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 4 novembre 2018
*/

/********************************************
* Titre: Travail pratique #4 - utilisateurRegulier.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurRegulier.h"

// Constructeurs
UtilisateurRegulier::UtilisateurRegulier(const string & nom, MethodePaiement methodePaiement, const string & courriel, const string & idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), possedeGroupe_(false)
{}

// Methode d'acces
bool UtilisateurRegulier::getPossedeGroupe() const {
	return possedeGroupe_;
}

// Methode de modification
void UtilisateurRegulier::setPossedeGroupe(bool possedeGroupe) {
	possedeGroupe_ = possedeGroupe;
}

void UtilisateurRegulier::print(ostream& os) const {
	string groupe = getPossedeGroupe() ? "dans un groupe" : "N'est pas dans un groupe";

	os << "Utilisateur (Regulier, " << groupe << ")"  << getNom() << " :" << endl;
	os << "\t\t Total a payer: " << getTotalATransferer() << "$ (" <<
		getBalance() << "$ de frais)" << endl;
}
