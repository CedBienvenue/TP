/////////////////////////////////////////////////////////////////////////////////////////////
////
//// Nom: Cédrik Bienvenue (1894296) et Mohamed Khairallah Gharbi (1837067)
//// Description: Implémentation des fonctions de la classe depense 
//// Date: 24 Septembre 2018
////
/////////////////////////////////////////////////////////////////////////////////////////////
#include "depense.h"


//Constructeurs 

//Constructeur par défaut 
Depense::Depense(){

    titre_ = "";
    montant_ = 0.0;
}

//Constructeur par paramètres
Depense::Depense(const string& titre, double montant ): titre_(titre), montant_(montant){
}

////////////////////////////////////////////
// Méthodes d'accès

//Retourne le titre de la dépense
string Depense::getTitre() const{

    return titre_;
}

//Retourne le montant de la dépense
double Depense::getMontant() const{

    return montant_;
}

///////////////////////////////////////////////
//Méthodes de modifications

//Permet de modifier le montant d'une dépense
void Depense::setMontant(double montant){

    montant_ = montant;
}

//Permet de modifier le titre d'une dépense
void Depense::setTitre(const string& titre){

    titre_ = titre;
}

///////////////////////////////////////////////
//Méthode d'affichage

void Depense::afficherDepense() const{

	cout << "Achat : " << this->getTitre() << " Prix : " << this->getMontant() << " ;" << endl;
}
