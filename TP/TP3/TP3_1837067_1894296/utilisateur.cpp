/*	Fichier : utilisateur.cpp

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification :21 Octobre 2018
*/
/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa 
*******************************************/

#include "utilisateur.h"

// Constructeurs
	//Constructeur par defaut : 

Utilisateur::Utilisateur() : nom_(""),interet_(0), type_(Regulier) {

}
	//Constructeur par parametres : 

Utilisateur::Utilisateur(const string& nom, TypeUtilisateur type) : nom_(nom), type_(type), interet_(0) {

}

	//Constructeur par copie : 

Utilisateur::Utilisateur(const Utilisateur& utilisateur) : nom_(utilisateur.nom_), interet_(utilisateur.interet_),
														   type_(utilisateur.type_), depenses_(utilisateur.depenses_), 
														   totalDepense_(utilisateur.totalDepense_) {

}

//Destucteur : 
Utilisateur::~Utilisateur() {
	depenses_.clear(); 
}

// Methodes d'acces

string Utilisateur::getNom() const {
	return nom_;
}

double Utilisateur::getTotalDepenses() const {
	return totalDepense_;
}

TypeUtilisateur Utilisateur::getType() const {
	return type_; 
}

double Utilisateur::getInteret() const {
	return interet_; 
}

unsigned int Utilisateur::getNombreDepenses() const {
	
	return depenses_.size();
}

vector <Depense*> Utilisateur::getDepenses() const {
	return depenses_; 
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}
void  Utilisateur::setType(const TypeUtilisateur type) {
	type_ = type; 
}

void Utilisateur::ajouterInteret(double montant) {
	
	interet_ += montant;
}

void Utilisateur::calculerTotalDepenses() {
	double total = 0;
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		if (depenses_[i]->getType() == groupe)
		{
			total += static_cast<DepenseGroupe*>(depenses_[i])->getMontantPersonnel();
		}
		else
		{
			total += depenses_[i]->getMontant();
		}
	}
	totalDepense_ = total; 
}


Utilisateur& Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
	return *this; 
}

Utilisateur& Utilisateur::operator=(Utilisateur * utilisateur)
{
	if (this != utilisateur)
	{
		nom_ = utilisateur->nom_;
		depenses_ = utilisateur->depenses_;
		interet_ = utilisateur->interet_; 
		totalDepense_ = utilisateur->totalDepense_;
		type_ = utilisateur->type_; 
	}
	return *this;
}




// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur) {
	string type;
	if (utilisateur.getType() == Regulier)
		type = "Regulier";
	else type = "Premium";

	os << "\t";
	os << "L'utilisateur : " << utilisateur.getNom() << "(" << type << ")" << " a depense pour un total de : " << utilisateur.getTotalDepenses()
		<< ",   PolyCount prend en interet : " << utilisateur.getInteret() << ", voici les depenses :" << endl;
	for (Depense* depense : utilisateur.getDepenses()) {
		if (depense->getType() == individuelle)
			os << *depense << endl;
		else os << *(static_cast <DepenseGroupe*>(depense)) << endl;
	}
	return os; 
}
