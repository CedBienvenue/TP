/////////////////////////////////////////////////////////////////////////////////////////////
////
//// Nom: Cédrik Bienvenue (1894296) et Mohamed Khairallah Gharbi (1837067)
//// Description: Implémentation des fonctions de la classe Groupe 
//// Date: 24 Septembre 2018
////
/////////////////////////////////////////////////////////////////////////////////////////////
#include "groupe.h"
#include <algorithm>

//Constructeurs

//Constructeur par défaut
Groupe::Groupe() {

	nom_ = "";
	totalDepenses_ = 0.0;
	listeUtilisateurs_ = nullptr;
	nombreDepenses_ = 0;
	nombreUtilisateurs_ = 0;
	tailleTabUtilisateurs_ = 5;
	tailleTabDepenses_ = 10;
	listeDepenses_ = nullptr;
	comptes_ = nullptr;
	listeTransferts_ = nullptr;
	nombreTrensferts_ = 0;
}

//Constructeur par paramètre
Groupe::Groupe(const string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs) : nom_(nom), 
tailleTabDepenses_(tailleTabDepenses), tailleTabUtilisateurs_(tailleTabUtilisateurs), totalDepenses_(0.0), 
nombreDepenses_(0), nombreTrensferts_(0), comptes_(nullptr), listeTransferts_(nullptr){

	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs];
	listeDepenses_ = new Depense*[tailleTabDepenses];
}

///////////////////////////////////////////
//Destructeur
Groupe::~Groupe() {
	delete comptes_;
	delete[] listeTransferts_;
	delete[] listeDepenses_;
	delete[] listeUtilisateurs_;	
}

////////////////////////////////////////////
//Méthodes d'accès

//Retourne le nom du groupe
string Groupe::getNom() const {
	return nom_;
}

//Retourne le nombre de dépense
unsigned int Groupe::getNombreDepenses() const{
	return nombreDepenses_;
}

//Retourne le total de dépense du groupe
double Groupe::getTotal() const{
	return totalDepenses_;
}

////////////////////////////////////////////
//Méthode de modification

//Permet de modifier le nom d'un groupe
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

////////////////////////////////////////////
//Méthode qui ajoute une dépense à l'utilisateur et au groupe
void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar) {

	for (unsigned int i = 0; i < nombreUtilisateurs_; i++){
		if (listeUtilisateurs_[i] == payePar){
			listeUtilisateurs_[i]->ajouterDepense(uneDepense);
		}
	}
	if (nombreDepenses_ >= tailleTabDepenses_){
		unsigned int nouvelleTaille = tailleTabDepenses_ * 2;
		Depense** nouvelleTable = new Depense*[nouvelleTaille];
		for (unsigned int i = 0; i < nombreDepenses_; i++){
			nouvelleTable[i] = listeDepenses_[i];
		}
		delete[] listeDepenses_;

		listeDepenses_ = nouvelleTable;
		tailleTabDepenses_ = nouvelleTaille;
	}
	listeDepenses_[nombreDepenses_++] = uneDepense;
}

////////////////////////////////////////////
//Méthode qui ajoute un utilisateur au groupe
void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur) {
	
	if (nombreUtilisateurs_ >= tailleTabUtilisateurs_){
		unsigned int nouvelleTaille = tailleTabUtilisateurs_ * 2;
		Utilisateur** nouvelleTable = new Utilisateur*[nouvelleTaille];
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++){
			nouvelleTable[i] = listeUtilisateurs_[i];
		}
		delete[] listeUtilisateurs_;

		listeUtilisateurs_ = nouvelleTable;
		tailleTabUtilisateurs_ = nouvelleTaille;
	}
	listeUtilisateurs_[nombreUtilisateurs_++] = unUtilisateur;
}

////////////////////////////////////////////
//Méthode qui calcule le total des dépenses du groupe
void Groupe::calculerTotalDepenses() {
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++){
		listeUtilisateurs_[i]->calculerTotal();
		totalDepenses_ += listeUtilisateurs_[i]->getTotal();
	}
	comptes_ = new double[nombreUtilisateurs_];
	double moyenneParUtilisateur = totalDepenses_ / nombreUtilisateurs_;
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++){
		comptes_[i] = (listeUtilisateurs_[i]->getTotal() - moyenneParUtilisateur);
	}
}

////////////////////////////////////////////
//Méthode qui équilibre les comptes de chaques utilisateurs du groupe 
void Groupe::equilibrerComptes() {
	
	double tempMax = comptes_[0];
	double tempMin = comptes_[0];
	double montantTransfert = 0.0;
	unsigned int donneur, receveur;
	int compteur;
	listeTransferts_ = new Transfert*[nombreUtilisateurs_];

	do{
		compteur = 0;
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++){
			
			tempMin = min(comptes_[i], tempMin);
			tempMax = max(comptes_[i], tempMax);
		}
		montantTransfert = min(tempMax, abs(tempMin));

		for (unsigned int i = 0; i < nombreUtilisateurs_; i++){
			if (comptes_[i] == tempMax && comptes_[i] != 0){
				comptes_[i] -= montantTransfert;
				tempMax = 0.0;
				receveur = i;
			}
			else if(comptes_[i] == tempMin && comptes_[i] != 0){
				comptes_[i] += montantTransfert;
				tempMin = 0.0;
				donneur = i;
			}
			if (comptes_[i] == 0){
				compteur++;
			}
		}

		listeTransferts_[nombreTrensferts_++] = new Transfert(montantTransfert, listeUtilisateurs_[donneur], listeUtilisateurs_[receveur]);
	} while (!(compteur == nombreUtilisateurs_));
}

////////////////////////////////////////////
//Méthode d'affichage
void Groupe::afficherGroupe() const{
	cout << "L'evenement : " << this->getNom() << " a coute un total pour le groupe de : " << endl <<
		this->getTotal() << " voici les depenses :" << endl;
	cout << "-----------------------------------------------------------------" << endl;
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++){
		listeUtilisateurs_[i]->afficherUtilisateur();
		cout << "-----------------------------------------------------------------" << endl;
	}

	if (nombreTrensferts_ == 0)
	{
		cout << "Soit les comptes suivants : " << endl;
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		{
			cout << listeUtilisateurs_[i]->getNom() << " : " << comptes_[i] << endl;
		}
	}
	else
	{
		cout << "Pour equilibrer : " << endl;
		for (unsigned int i = 0; i < nombreTrensferts_; i++)
		{
			listeTransferts_[i]->afficherTransfert();
		}
	}
}