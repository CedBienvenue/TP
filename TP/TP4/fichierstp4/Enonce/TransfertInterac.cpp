/*
	Fichier : transfertinterac.cpp

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 4 novembre 2018
*/

/********************************************
* Titre: Travail pratique #4 - transfertInterac.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfertInterac.h"
//Constructeurs :
TransfertInterac::TransfertInterac(double montant, Utilisateur* expediteur, Utilisateur* receveur)
	: Transfert(montant, expediteur, receveur)
{
	courriel_ = receveur->getCourriel();
}
//Destructeurs : 
TransfertInterac::~TransfertInterac()
{
}
//Methode d'acces : 
string TransfertInterac::getCourriel() const
{
	return courriel_;
}

// Methode qui retourne les frais relier à un transfert.
double TransfertInterac::getFraisTransfert() const {

	if (dynamic_cast<UtilisateurPremium*>(expediteur_) != nullptr)
		return 0;
	else
	{
		return FRAIS_TRANSFERT;
	}
}
//Methode de modification : 
void TransfertInterac::setcourriel(string courriel)
{
	courriel_ = courriel;
}
