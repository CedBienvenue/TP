/********************************************
* Titre: Travail pratique #4 - transfertPaypal.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertPaypal.h"

TransfertPaypal::TransfertPaypal(double montant, Utilisateur * expediteur, Utilisateur * receveur)
	: Transfert(montant, expediteur, receveur)
{
	id_ = expediteur->getIdPaypal();
}

string TransfertPaypal::getId() const
{
	return id_;
}

double TransfertPaypal::getFraisTransfert() const{
	
	UtilisateurPremium* userPremium = dynamic_cast<UtilisateurPremium*>(getExpediteur());
	if (userPremium)
	{
		return -(getMontant() * 0.03);
	}
	else
	{
		return (getMontant() * COMMISSION) + FRAIS;
	}
	
}

void TransfertPaypal::setId(string id)
{
	id_ = id;
}

