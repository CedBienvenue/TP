/*
	Fait par :  Cedrik Bienvenue ()
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 30 septembre 2018

*/
/********************************************
* Titre: Travail pratique #2 - transfert.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "transfert.h"

// Constructeurs
Transfert::Transfert() : montant_(0), expediteur_(nullptr), receveur_(nullptr) {
}

Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) : 
	montant_(montant), expediteur_(expediteur), receveur_(receveur) {
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

//Methode affichage
ostream& operator<<(ostream& output,const Transfert& transfert) {
	return output << "Transfert fait part : " << transfert.getExpediteur()->getNom() << " pour : " << transfert.getReceveur()->getNom()
		<< " d'un montant de : " << transfert.getMontant() << endl;
}
