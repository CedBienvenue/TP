/********************************************
* Titre: Travail pratique #4 - transfertPaypal.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertPaypal.h"

TransfertPaypal::TransfertPaypal(double montant, Utilisateur * expediteur, Utilisateur * receveur)
	: Transfert(montant, expediteur, receveur)
{
}

string TransfertPaypal::getId() const
{
	return id_;
}

double TransfertPaypal::getFraisTransfert() const{
	if (typeid(getExpediteur()) != typeid(UtilisateurPremium))
	{
		double montantFrais = (getMontant() * COMMISSION) + FRAIS;
		getExpediteur()->modifierBalanceFrais(montantFrais);
	}
	double montantRemise = -(getMontant() * 0.03);
	getExpediteur()->modifierBalanceFrais(montantRemise);
}

void TransfertPaypal::setId(string id)
{
	id_ = id;
}

