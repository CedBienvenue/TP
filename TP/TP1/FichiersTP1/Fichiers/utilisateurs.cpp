/////////////////////////////////////////////////////////////////////////////////////////////
////
//// Nom: Cédrik Bienvenue (1894296) et Mohamed Khairallah Gharbi (1837067)
//// Description: Implémentation des fonctions de la classe Utilisateur 
//// Date: 24 Septembre 2018
////
/////////////////////////////////////////////////////////////////////////////////////////////
#include "utilisateur.h"

//Constructeurs

//Constructeur par defaut
Utilisateur::Utilisateur(){

    nom_ = "";
    tailleTabDepense_ = 5;
    nombreDepenses_ = 0;
    totalDepense_ = 0;
    listeDepenses_ = nullptr;
}

//Constructeur par parametres
Utilisateur::Utilisateur(const string& nom): nom_(nom), tailleTabDepense_(5), nombreDepenses_(0),
 totalDepense_(0){
    listeDepenses_ = new Depense*[tailleTabDepense_];
}

///////////////////////////////////////////
//Destructeur
Utilisateur::~Utilisateur() {

	delete[] listeDepenses_;
}

////////////////////////////////////////////
//Méthodes d'accès

//Retourne le nom de l'utilisateur
string Utilisateur::getNom() const {
    return nom_;
}

//Retourne le nombre de dépense d'un utilisateur
unsigned int Utilisateur::getNombreDepense() const {

    return nombreDepenses_;
}

//Retourne le total de dépense d'un utilisateur
double Utilisateur::getTotal() const {

    return totalDepense_;
}

////////////////////////////////////////////
//Méthode de modification

//Permet de modifier le nom d'un utilisateur
void Utilisateur::setNom(const string& nom){

    nom_ = nom;
}

////////////////////////////////////////////
//Méthode qui ajoute une dépense à l'utilisateur
void Utilisateur::ajouterDepense(Depense* uneDepense){

	if (nombreDepenses_ >= tailleTabDepense_){
		int nouvelleTaille = tailleTabDepense_ * 2;
		Depense** nouvelleTable = new Depense*[nouvelleTaille];
		
		for (unsigned int i = 0; i < nombreDepenses_; i++){
			nouvelleTable[i] = listeDepenses_[i];
		}

		delete[] listeDepenses_;

		listeDepenses_ = nouvelleTable;
		tailleTabDepense_ = nouvelleTaille;
	}

    listeDepenses_[nombreDepenses_++] = uneDepense;
}

////////////////////////////////////////////
//Méthode qui calcul total des dépenses de l'utilisateur
void Utilisateur::calculerTotal() {

	for (unsigned int i = 0; i < nombreDepenses_; i++){
		totalDepense_ += listeDepenses_[i]->getMontant();
	}
}

////////////////////////////////////////////
//Méthode d'affichage
void Utilisateur::afficherUtilisateur() const {

	cout << "Utilisateur : " << this->getNom() << " a depense pour un total de : " << this->getTotal() << endl
		<< "Liste de depenses : " << endl;
	for (unsigned int i = 0; i < nombreDepenses_; i++){
		listeDepenses_[i]->afficherDepense();
	}
}