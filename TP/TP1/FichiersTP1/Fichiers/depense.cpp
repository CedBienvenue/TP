/////////////////////////////////////////////////////////////////////////////////////////////
////
//// Nom: C�drik Bienvenue (1894296) et Mohamed Khairallah Gharbi (1837067)
//// Description: Impl�mentation des fonctions de la classe depense 
//// Date: 24 Septembre 2018
////
/////////////////////////////////////////////////////////////////////////////////////////////
#include "depense.h"


//Constructeurs 

//Constructeur par d�faut 
Depense::Depense(){

    titre_ = "";
    montant_ = 0.0;
}

//Constructeur par param�tres
Depense::Depense(const string& titre, double montant ): titre_(titre), montant_(montant){
}

////////////////////////////////////////////
// M�thodes d'acc�s

//Retourne le titre de la d�pense
string Depense::getTitre() const{

    return titre_;
}

//Retourne le montant de la d�pense
double Depense::getMontant() const{

    return montant_;
}

///////////////////////////////////////////////
//M�thodes de modifications

//Permet de modifier le montant d'une d�pense
void Depense::setMontant(double montant){

    montant_ = montant;
}

//Permet de modifier le titre d'une d�pense
void Depense::setTitre(const string& titre){

    titre_ = titre;
}

///////////////////////////////////////////////
//M�thode d'affichage

void Depense::afficherDepense() const{

	cout << "Achat : " << this->getTitre() << " Prix : " << this->getMontant() << " ;" << endl;
}
