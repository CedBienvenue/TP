/*	Fichier : depenseGroupe.cpp

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 21 Octobre 2018

*/
#include "depenseGroupe.h"

// Constructeurs

DepenseGroupe::DepenseGroupe(const string& nom, double montant, const string& lieu, unsigned int nbParticipants) : Depense(nom, montant, lieu, groupe),
nombreParticipants_(nbParticipants) {
	
}
DepenseGroupe::DepenseGroupe(const DepenseGroupe& depense): Depense(depense), nombreParticipants_(depense.nombreParticipants_){
}

// Méthodes accès

unsigned int DepenseGroupe::getNombreParticipants() const {
	return nombreParticipants_;
}
double DepenseGroupe::getMontantPersonnel() const {
	if (nombreParticipants_ == 0)
	{
		return 0;
	}
	return getMontant() / getNombreParticipants();
}

// Méthode de modifications

void DepenseGroupe::setNombreParticipants(unsigned int nombre) {
	nombreParticipants_ = nombre;
}

// Méthode d'affichage

ostream& operator<<(ostream& os, const DepenseGroupe& depense) {
	os << "\t\t";
	os << "Depense groupe :   Achat fait (a " << *depense.getLieu() << ")   : " <<
		depense.getNom() << " Prix : " << depense.getMontant() << " fait par : " << depense.nombreParticipants_ <<
		" soit : " << depense.getMontantPersonnel() << " par personne." << endl;
	return os;
}