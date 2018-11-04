/*
	Fichier : transfertPaypal.cpp

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 4 novembre 2018
*/

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

// Methode qui retourne les frais relier à un transfert.
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

