/********************************************
* Titre: Travail pratique #4 - transfertPaypal.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertPaypal.h"
// Constructeur : 
TransfertPaypal::TransfertPaypal(double montant, Utilisateur * expediteur, Utilisateur * receveur)
	: Transfert(montant, expediteur, receveur)
{
	id_ = expediteur->getIdPaypal();
}
//Destructeur : 
TransfertPaypal::~TransfertPaypal()
{
}
 //Methode d'acces : 
string TransfertPaypal::getId() const
{
	return id_;
}

double TransfertPaypal::getFraisTransfert() const{
	if (dynamic_cast<UtilisateurPremium*>(expediteur_) != nullptr)
		return 0;
	{
		return (getMontant() * COMMISSION + FRAIS);
	}
	
}
//Methode de modification : 
void TransfertPaypal::setId(string id)
{
	id_ = id;
}

