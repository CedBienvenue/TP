/*
	Fichier : transfertPaypal.cpp

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 18 novembre 2018
*/

/********************************************
* Titre: Travail pratique #4 - transfertPaypal.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertPaypal.h"

TransfertPaypal::TransfertPaypal(double montant, Utilisateur * expediteur, Utilisateur * receveur)
	: Transfert(montant, expediteur, receveur), id_(expediteur->getIdPaypal())
{
}

string TransfertPaypal::getId() const
{
	return id_;
}

void TransfertPaypal::setId(string id)
{
	id_ = id;
}

double TransfertPaypal::getFraisTransfert() const
{
	if (dynamic_cast<UtilisateurPremium*>(expediteur_) == nullptr) {
		return montant_ * (COMMISSION) + FRAIS;
	}
	else {
		return 0;
	}
}
