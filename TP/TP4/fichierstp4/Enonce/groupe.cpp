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

Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string& lieu) {
	
	bool payeParPresent = false;
	for (unsigned int i = 0; i < utilisateurs_.size(); i++)
	{
		if (payePar == utilisateurs_[i])
		{
			Depense* depense = new Depense(nom, montant, lieu);
			depenses_.push_back(depense);
			*payePar += depense;
			payeParPresent = true;
		}
	}
	if (!payeParPresent)
	{
		cout << "ERREUR : L'utilisateur " << payePar->getNom() << " ne fait pas partie du groupe ." << endl;
	}
	else
	{
		double montantParUtilisateur = montant / utilisateurs_.size();

		if (comptes_.size() != utilisateurs_.size())
		{
			for (unsigned int i = 0; i < utilisateurs_.size(); i++)
			{
				comptes_.push_back(0);
			}
		}

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

		// Appel de la méthode effectuer transfert pour mettre à jour la balance des frais et des transferts.
		transferts_[indexTransfert]->effectuerTransfert();
		// Incrémentation de l'index du vecteur transfert.
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
	if (userPremium)
	{
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
