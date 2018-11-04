/*
	Fichier : groupe.cpp

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 4 novembre 2018
*/

/********************************************
* Titre: Travail pratique #4 - groupe.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "groupe.h"

// Constructeurs

Groupe::Groupe() {
	nom_ = "";
}

Groupe::Groupe(const string& nom) : nom_(nom) {
}

//Destructeurs : 
Groupe::~Groupe() {
	//Supprimer vecteur utilisateurs_:
	for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
		delete utilisateurs_[i];
	}
	utilisateurs_.clear();

	//Supprimer vecteur depenses_:
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		delete depenses_[i];
	}
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

vector<Depense*> Groupe::getDepenses() const
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

vector<double> Groupe::getComptes() const
{
	return comptes_;
}

double Groupe::getTotalDepenses() const {
	double totalDepenses = 0;
	for (unsigned int i = 0; i < depenses_.size(); i++) {
		totalDepenses += depenses_[i]->getMontant();
	}
	return totalDepenses;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methode qui permet d'ajouter une dépense au groupe et à l'utilisateur. Aussi, elle permet de mettre à jour les comptes de chaques utilisateurs. 

Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string& lieu) {
	
	bool payeParPresent = false;

	// Vérification si l'utilisateur payePar est bien dans le groupe.
	for (unsigned int i = 0; i < utilisateurs_.size() ; i++)
	{
		if (payePar->getNom() == utilisateurs_[i]->getNom())
		{
			Depense* depense = new Depense(nom, montant, lieu);
			// Ajout dépense au groupe
			depenses_.push_back(depense);
			// Ajout dépense à l'utilisateur
			*payePar += depense;
			payeParPresent = true;
		}
	}
	if (payeParPresent)
	{
		double montantParUtilisateur = montant / utilisateurs_.size();

		// Initialisation des comptes à zéro pour par la suite incrémenter
		if (comptes_.size() != utilisateurs_.size())
		{
			for (unsigned int i = 0; i < utilisateurs_.size(); i++)
			{
				comptes_.push_back(0);
			}
		}

		// Incrementation des comptes utilisateurs.
		for (unsigned int i = 0; i < utilisateurs_.size(); i++)
		{
			if (payePar == utilisateurs_[i])
			{
				comptes_[i] += (montant - montantParUtilisateur);
			}
			else
			{
				comptes_[i] -= montantParUtilisateur;
			}
		}
	}
	return *this;
}

void Groupe::equilibrerComptes() {

	bool calcul = true;
	unsigned int count = 0;
	int indexTransfert = 0;
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
			// Faire le transfert  du bon type
			if (utilisateurs_[indexMin]->getMethodePaiement() == Paypal)
			{
				transferts_.push_back(new TransfertPaypal(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			}
			else
			{
				transferts_.push_back(new TransfertInterac(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			}
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else if (-min > max  && min != 0 && max != 0) {
			// Faire le transfert du bon type
			if (utilisateurs_[indexMin]->getMethodePaiement() == Paypal)
			{
				transferts_.push_back(new TransfertPaypal(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			}
			else
			{
				transferts_.push_back(new TransfertInterac(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			}
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}

		// Appel de la methode effectuer transfert pour mettre a jour la balance des frais et des transferts.
		transferts_[indexTransfert]->effectuerTransfert();
		// Incrementation de l'index du vecteur transfert.
		indexTransfert++;
		
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

Groupe& Groupe::operator+=(Utilisateur* utilisateur) {

	UtilisateurPremium* userPremium = dynamic_cast<UtilisateurPremium*>(utilisateur);
	UtilisateurRegulier* userRegulier = dynamic_cast<UtilisateurRegulier*>(utilisateur);
	// Verification du type d'utilisateur
	if (userPremium)
	{
		// Verification si l'abonnement est toujours valide.
		if (userPremium->getJoursRestants() != 0)
		{
			utilisateurs_.push_back(utilisateur);
		}
		else
		{
			cout << "ERREUR : L'utilisateur " << utilisateur->getNom() << " doit renouveler son abonnement premium." << endl;
		}
	}
	else
	{
		// Verification si l'utilisateur regulier appartient à un groupe
		if (userRegulier->getPossedeGroupe() == false)
		{
			utilisateurs_.push_back(utilisateur);
			userRegulier->setPossedeGroupe(true);
		}
		else
		{
			cout << "ERREUR : L'utilisateur " << utilisateur->getNom() << " n'est pas un utilisateur premium et est deja dans un groupe." << endl;
		}
	}
	return *this;
}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	for (unsigned int i = 0; i < groupe.utilisateurs_.size(); i++) {
		os <<"\t- " << *groupe.utilisateurs_[i]  << " \n\n";
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (unsigned int i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
		for (unsigned int i = 0; i < groupe.comptes_.size(); i++) {
			os << groupe.utilisateurs_[i]->getNom() << " : " << groupe.comptes_[i] << endl;
		}
	}

	os << endl;
	return os;
}
