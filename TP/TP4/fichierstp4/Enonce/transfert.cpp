/*
	Fichier : transfert.cpp

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 4 novembre 2018
*/

/********************************************
* Titre: Travail pratique #4 - transfert.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "transfert.h"

// Constructeurs
Transfert::Transfert() : montant_(0), expediteur_(nullptr), receveur_(nullptr) {
}

Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) : 
	montant_(montant), expediteur_(expediteur), receveur_(receveur) {
}
// Destructeurs : 
Transfert::~Transfert()
{
	
}

// Methodes d'acces
double Transfert::getMontant() const {
	return montant_;
}

Utilisateur* Transfert::getExpediteur() const {
	return expediteur_;
}

Utilisateur* Transfert::getReceveur() const {
	return receveur_;
}

// Methodes de modifications
void Transfert::setMontant(double montant) {
	montant_ = montant;
}

void Transfert::setExpediteur(Utilisateur *donneur) {
	expediteur_ = donneur;
}

void Transfert::setReceveur(Utilisateur *receveur) {
	receveur_ = receveur;
}

// Methode qui modifie la balance transfert et frais des receveurs et expediteurs lors d'un transfert.
void Transfert::effectuerTransfert() {
	getReceveur()->modifierBalanceTranferts(-(getMontant()));
	getExpediteur()->modifierBalanceTranferts(getMontant());

	if (dynamic_cast<UtilisateurPremium*>(expediteur_) != nullptr)
		expediteur_->modifierBalanceFrais((-montant_) * TAUX_EPARGNE);
	else
		expediteur_->modifierBalanceFrais(getFraisTransfert());
}

//Methode affichage
ostream& operator<<(ostream& os, const Transfert& transfert) {
	os << transfert.getExpediteur()->getNom() << "\t -> " << transfert.getReceveur()->getNom() <<
		"\t : " << transfert.getMontant() << "$" << endl;
	return os;
}
