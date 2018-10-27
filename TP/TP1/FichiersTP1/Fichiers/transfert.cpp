/////////////////////////////////////////////////////////////////////////////////////////////
////
//// Nom: Cédrik Bienvenue (1894296) et Mohamed Khairallah Gharbi (1837067)
//// Description: Implémentation des fonctions de la classe transfert
//// Date: 24 Septembre 2018
////
/////////////////////////////////////////////////////////////////////////////////////////////

#include "transfert.h"

//Constructeurs 

//Constructeur par defaut
Transfert::Transfert(){
	montant_ = 0.0;
	donneur_ = nullptr;
	receveur_ = nullptr;
}

//Constructeur par parametres
Transfert::Transfert(double montant, Utilisateur* de, Utilisateur* pour) : montant_(montant), 
donneur_(de), receveur_(pour){

}

////////////////////////////////////////////
//Méthodes d'accès

//Retourne le donneur d'une transaction
Utilisateur* Transfert::getDonneur() const {
	
	return donneur_;
}

//Retourne le receveur d'une transaction
Utilisateur* Transfert::getReceveur() const {
	return receveur_;
}

//Retourne le montant d'une transaction
double Transfert::getMontant() const{
	return montant_;
}

///////////////////////////////////////////////
//Méthodes de modifications

//Permet de modifier le donneur d'une transaction
void Transfert::setDonneur(Utilisateur* donneur) {
	donneur_ = donneur;
}

//Permet de modifier le donneur d'une transaction
void Transfert::setMontant(double montant) {
	montant_ = montant;
}

//Permet de modifier le donneur d'une transaction
void Transfert::setReceveur(Utilisateur* receveur) {
	receveur_ = receveur;
}

///////////////////////////////////////////////
//Méthode d'affichage

void Transfert::afficherTransfert() const{
	cout << "Transfert fait part : " << this->getDonneur()->getNom() << " pour : " << this->getReceveur()->getNom()
		<< " d'un montant de : " << montant_ << endl;

}