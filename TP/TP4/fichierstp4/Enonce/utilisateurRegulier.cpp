/********************************************
* Titre: Travail pratique #4 - utilisateurRegulier.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateurRegulier.h"

UtilisateurRegulier::UtilisateurRegulier(const string & nom, MethodePaiement methodePaiement, const string & courriel, const string & idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), possedeGroupe_(false)
{}


bool UtilisateurRegulier::getPossedeGroupe() const {
	return possedeGroupe_;
}

void UtilisateurRegulier::setPossedeGroupe(bool possedeGroupe) {
	possedeGroupe_ = possedeGroupe;
}

void UtilisateurRegulier::print(ostream& os) const {
	string groupe;

	if (getPossedeGroupe())
	{
		groupe = "dans un groupe";
	}
	else
	{
		groupe = "N'est pas dans un groupe";
	}
	os << "Utilisateur (Regulier, " << groupe << ")"  << getNom() << " :" << endl;
	os << "\t\t Total a payer: " << getTotalATransferer() << "$ (" <<
		getBalance() << "$ de frais)" << endl;
}
