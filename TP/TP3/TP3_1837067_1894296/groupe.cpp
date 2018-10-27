/*	Fichier : groupe.cpp

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 21 Octobre 2018

*/
/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "groupe.h"

// Constructeurs

Groupe::Groupe() : nom_(""),totalDepenses_(0)   {
}
Groupe::Groupe(const string& nom) : nom_(nom), totalDepenses_(0) {
}

// Destructeur
Groupe::~Groupe() {
	//Supprimer vecteur utilisateurs_:
	utilisateurs_.clear();

	//Supprimer vecteur depenses_:
	depenses_.clear(); 

	//Supprimer vecteur transferts_:
	for (unsigned int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}
	transferts_.clear(); 

	//Supprimer vecteur comptes_ : 
	comptes_.clear(); 
}


// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

vector<DepenseGroupe*> Groupe::getDepenses() const
{
	return depenses_;
}

vector<Utilisateur*> Groupe::getUtilisateurs() const
{
	return utilisateurs_;
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}


double Groupe::getTotalDepenses() const {

	return totalDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour)
{
	//1ere condition : Verifier que tous les utilisateurs concernés soient là 
	// Verifiser si PayePar est present : 
	bool testPayeParPresent = false; 
	unsigned int i = 0; 
	while ((i < utilisateurs_.size()) && testPayeParPresent == false) {
		if (payePar->getNom() == utilisateurs_[i]->getNom()) 
			testPayeParPresent = true;
		else i++; 
	}
	//Afficher un message d'erreur si le payePar est introuvable : 
	if (testPayeParPresent == false) {
		cout << "ERREUR : L'utilisateur payePar est manquant " << endl;
	}
	// Terminer sinon : 
	else {
		//Verifier si payePour sont presents : 
		unsigned int nombrePayePour = 0;
		unsigned int j = 0;
		while ( j < payePour.size() && nombrePayePour < payePour.size() ) {
			for (unsigned int k = 0; k < utilisateurs_.size(); k++)
				if (payePour[j]->getNom() == utilisateurs_[k]->getNom())
					nombrePayePour++; 
			j++; 
		}
		//Afficher un message d'erreur si le payePour est introuvable totalement : 
		if (nombrePayePour != payePour.size() || depense->getType() != groupe) {
			cout << "ERREUR : vous tentez d'ajouter une depense individuelle au groupe ou alors les personnes impliquees dans la depense groupe ne sont pas dans le groupe" << endl; 
		}
			
		//Terminer sinon : 
		else { 
			// Initialisation du vecteur compte à 0 pour incémenter par la suite à chaque dépense.
			if (comptes_.size() != utilisateurs_.size())
			{
				for (unsigned int i = 0; i < utilisateurs_.size(); i++)
				{
					comptes_.push_back(0);
				}
			}
			//	*Ajoute la dépense aux utilisateurs concernés : 
			for (unsigned int i = 0; i < payePour.size(); i++) {
					
				*payePour[i] += depense;
			}
			*payePar += depense; 
			//  *Mets à jour les comptes des utilisateurs concernés
			double moyenne;
			static_cast<DepenseGroupe*>(depense)->setNombreParticipants(payePour.size() + 1);
			moyenne = depense->getMontant() / static_cast<DepenseGroupe*>(depense)->getNombreParticipants();
			for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
				if (payePar->getNom() == utilisateurs_[i]->getNom()) 
					comptes_[i] += (depense->getMontant() - moyenne);
					
				for (unsigned int j = 0; j < payePour.size(); j++) {
					if (payePour[j]->getNom() == utilisateurs_[i]->getNom())
						comptes_[i] -= moyenne;
				}
			}
			//	*Ajoute la dépense au groupe
			depenses_.push_back(static_cast<DepenseGroupe*>(depense)); 
		}	
		
	}
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{	
	// Il faut savoir le type de l'utilisateur, soit regulier ( peut appartenir à un seul groupe) soit Premium :
	// Si c'est un utilisateur Regulier, il faut verifier qu'il n'est pas deja dans un groupe ,
	//	c'est-à-dire il faut que : estGroupe soit faux. Sinon, on ne peut pas l'ajouter 
	
	if (utilisateur->getType() == Regulier) {
		if (static_cast<UtilisateurRegulier*>(utilisateur)->estGroupe()) { 
			cout << "ERREUR : "<< utilisateur->getNom() <<" est un utilisateur non Premium et appartient deja a un groupe. " << endl; 
		}
		else {
			utilisateurs_.push_back(utilisateur);
			static_cast<UtilisateurRegulier*>(utilisateur)->setEtatGroupe(true);
		}
			
	}
	//Sinon : c'est un utilisateur Premium, on vérifie si son abonnement est toujours valide. Pour le groupe on ne vérifie pas car, peut appartenir à plusieurs groupes. 
	else {
		if (static_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants() == 0)
		{
			cout << "ERREUR : L'utilisateur : " << utilisateur->getNom() << " doit renouveler sont abonnement premium" << endl;
		}else
			utilisateurs_.push_back(utilisateur);
	}
	return *this; 
}

void Groupe::equilibrerComptes() {
	
	bool calcul = true;
	unsigned int count = 0;
	double montant = 0.0;
	
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
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
		if (-min <= max && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));

			// Calcul du taux et ajout de l'interet
			if (utilisateurs_[indexMin]->getType() == Premium)
			{
				montant = (-min * static_cast<UtilisateurPremium*>(utilisateurs_[indexMin])->getTaux());
			}
			else
			{
				montant = (-min * TAUX_REGULIER);
			}
			utilisateurs_[indexMin]->ajouterInteret(montant);
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
	
		}
		else if (-min > max  && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));

			// Calcul du taux et ajout de l'interet
			if (utilisateurs_[indexMin]->getType() == Premium)
			{
				montant = (max * static_cast<UtilisateurPremium*>(utilisateurs_[indexMin])->getTaux());
			}
			else
			{
				montant = (max * TAUX_REGULIER);
			}
			utilisateurs_[indexMin]->ajouterInteret(montant);
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

void Groupe::calculerTotalDepense() {

	// On calcule le total des dépenses Groupe
	for (unsigned int i = 0; i < depenses_.size(); i++)
	{
		totalDepenses_ += depenses_[i]->getMontant();
	}

	// On calcule le total des dépenses pour chaque utilisateurs et on calcule le taux final selon le nombre de dépense
	for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
		utilisateurs_[i]->calculerTotalDepenses();
		if (utilisateurs_[i]->getType() == Premium)
		{
			static_cast<UtilisateurPremium*>(utilisateurs_[i])->calculerTaux();
		}
	}
}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	os << "L'evenement nomme : " << groupe.getNom() << " a coute un total (en terme de depenses groupees) : "
		<< groupe.getTotalDepenses() << ", voici les utilisateurs et toute leur depenses : \n\n";
	for (unsigned int i = 0; i < groupe.utilisateurs_.size(); i++) {
		os << *groupe.utilisateurs_[i];
		if (groupe.utilisateurs_[i]->getType() == Premium)
		{
			os << "( Taux final de " << static_cast<UtilisateurPremium*>(groupe.utilisateurs_[i])->getTaux() * 100 << " % )" << endl;
		}
	}
	os << endl;
	if (groupe.transferts_.size() != 0) {
		os << "Les transferts suivants ont ete realises pour equilibrer : " << endl;
		for (unsigned int i = 0; i < groupe.transferts_.size(); i++) {
			os << "\t";
			os << *groupe.transferts_[i];
		}
	}
	os << endl;
	return os; 
}
