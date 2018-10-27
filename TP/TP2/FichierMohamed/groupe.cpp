/*
	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 30 septembre 2018

*/
/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() :
	nom_("")
{
}

Groupe::Groupe(const string& nom) :
	nom_(nom)
{
}


Groupe::~Groupe() {
	depenses_.clear(); 
	transferts_.clear(); 
	utilisateurs_.clear(); 
	comptes_.clear(); 

}


// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

unsigned int Groupe::getNombreDepenses() const {
	return depenses_.size();
}

double Groupe::getTotalDepenses() const {
	double total = 0;
	unsigned int nombreDepense = getNombreDepenses(); 
	for (unsigned int i = 0; i < nombreDepense ; i++ ) {
		total += depenses_[i]->getMontant() ;
	}
	return total;
}

unsigned int Groupe::getNombreTransfert() const  {
	return transferts_.size(); 
}
// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* utilisateur) {
	depenses_.push_back(depense); 
	*utilisateur += depense; 
	return *this; 
}

Groupe& Groupe::operator+= ( Utilisateur* utilisateur) {
	utilisateurs_.push_back(utilisateur); 
	return *this; 
}

void Groupe::calculerComptes()
{	
	double moyenne = getTotalDepenses() / utilisateurs_.size();
	for (Utilisateur* utilisateur : utilisateurs_) {
		comptes_.push_back((utilisateur->getTotalDepenses()) - moyenne);
	}
}

void Groupe::equilibrerComptes() {
	calculerComptes();
	bool calcul = true;
	unsigned int count = 0;
	unsigned int nombreUsers(utilisateurs_.size()); 
	while (calcul) {
		double max = 0;
		double min = 0;
		unsigned int indexMax = 0;
		unsigned int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (unsigned int i = 0; i < nombreUsers; i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max) {
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}
}


// Methode d'affichage
ostream& operator<< (ostream& output, const Groupe* groupe) {
	output  << "L'evenement " << groupe->getNom() << " a coute un total de "
			<< groupe->getTotalDepenses() << " :  \n\n";
	for (unsigned int i = 0; i < groupe->utilisateurs_.size(); i++) {
		output << *groupe->utilisateurs_[i]; 
	}
	output << endl; 
	if (groupe->getNombreTransfert() != 0) {
		output << "Les transferts suivants ont ete realises pour equilibrer : " << endl; 
		for (unsigned int i = 0; i < groupe->transferts_.size(); i++) {
			output << "\t"; 
			output << *groupe->transferts_[i]; 
		}
	}
	else {
		output << "Les comptes ne sont pas equilibres " << endl << endl; 
	}
	output << endl; 
	return output; 
}

