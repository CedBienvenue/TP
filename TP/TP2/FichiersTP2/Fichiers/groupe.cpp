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
#include <ostream>
// Constructeurs
Groupe::Groupe() :nom_("")
{
}

Groupe::Groupe(const string& nom) :nom_(nom)
{
}

// Destructeur
Groupe::~Groupe() {
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
	for (unsigned int i = 0; i < getNombreDepenses(); i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
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

Groupe& Groupe::operator+= (Utilisateur* utilisateur) {
	utilisateurs_.push_back(utilisateur);
	return *this; 
}

void Groupe::calculerComptes()
{
	int nombreUsers = utilisateurs_.size();
	double moyenne = getTotalDepenses() / nombreUsers;
	for (int i = 0; i < nombreUsers; i++) {
		
		comptes_.push_back((utilisateurs_[i]->getTotalDepenses()) - moyenne);
	}
}

// Méthode équilibrer comptes

void Groupe::equilibrerComptes() {
	calculerComptes();
	bool calcul = true;
	int count = 0;
	int nombreUsers = utilisateurs_.size();
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < nombreUsers; i++) {
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
			Transfert* transfert = new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]);
			transferts_.push_back(transfert);
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else {
			Transfert* transfert = new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]);
			transferts_.push_back(transfert);
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= nombreUsers - 1) {
			calcul = false;
		}
	}
}


// Methode d'affichage
ostream& operator<< (ostream &output, const Groupe &groupe) {
	output  << "L'evenement " << groupe.nom_ << " a coute un total de "
			<< groupe.getTotalDepenses() << " :  \n\n";
	for (unsigned int i = 0; i < groupe.utilisateurs_.size(); i++) {
		output << *groupe.utilisateurs_[i]; 
	}
	for (unsigned int i = 0; i < groupe.comptes_.size(); i++)
	{
		output << groupe.comptes_[i] << endl;
	}
	output << endl; 
	if (groupe.transferts_.size() != 0) {
		
		output << "Les transferts suivants ont ete realises pour equilibrer : " << endl; 
		for (unsigned int i = 0; i < groupe.transferts_.size(); i++) {
			output << "\t"; 
			output << *groupe.transferts_[i]; 
		}
	}
	else {
		output << "Les comptes ne sont pas equilibres " << endl << endl;
		
	}
	output << endl; 
	return output; 
}

