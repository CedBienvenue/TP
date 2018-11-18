/********************************************
* Titre: Travail pratique #5 - groupe.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() {
	nom_ = "";
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::Groupe(const string& nom) : nom_(nom) {
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::~Groupe() {
	
	for (unsigned int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}

	delete gestionnaireDepenses_;
	delete gestionnaireUtilisateurs_;
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

// TODO : À modifier :
vector<Depense*> Groupe::getDepenses() const
{
	return gestionnaireDepenses_->getConteneur();
}

// TODO : À modifier :
map<Utilisateur*, double> Groupe::getUtilisateurs() const
{
	return gestionnaireUtilisateurs_->getConteneur();
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}

// TODO : À modifier :
vector<double> Groupe::getComptes() const {
	return gestionnaireUtilisateurs_->getComptes();
}

double Groupe::getTotalDepenses() const {
	return gestionnaireDepenses_->getTotalDepenses();
}

GestionnaireUtilisateurs * Groupe::getGestionnaireUtilisateurs()
{
	return gestionnaireUtilisateurs_;
}

GestionnaireDepenses * Groupe::getGestionnaireDepenses()
{
	return gestionnaireDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
// TODO : À modifier :
Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string& lieu)
{
	// Verification si l'utilisateur payePar est dans le groupe.
	if (!gestionnaireUtilisateurs_->estExistant(payePar))
	{
		return *this;
	}

	Depense* depense = new Depense(nom, montant, lieu);

	// Ajouté :
	gestionnaireDepenses_->ajouter(depense);

	*payePar += depense;

	// Mise a jour des comptes
	gestionnaireUtilisateurs_->mettreAJourComptes(payePar, depense->getMontant());
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	// Ajouté :
	UtilisateurPremium* userPremium = dynamic_cast<UtilisateurPremium*>(utilisateur);
	UtilisateurRegulier* userRegulier = dynamic_cast<UtilisateurRegulier*>(utilisateur);

	if (userPremium)
	{
		if (userPremium->getJoursRestants() != 0)
		{
			gestionnaireUtilisateurs_->ajouter(utilisateur);
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
			gestionnaireUtilisateurs_->ajouter(utilisateur);
			userRegulier->setPossedeGroupe(true);
		}
		else
		{
			cout << "ERREUR : L'utilisateur " << utilisateur->getNom() << " n'est pas un utilisateur premium et est deja dans un groupe." << endl;
		}
	}
	return *this;
}

// TODO : À modifier :
void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	while (calcul) {
		// On cherche le compte le plus eleve et le moins eleve
		pair<Utilisateur*, double>& userMax = gestionnaireUtilisateurs_->getMax();
		pair<Utilisateur*, double>& userMin = gestionnaireUtilisateurs_->getMin();
		double max = userMax.second;
		double min = userMin.second;
		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max && min != 0 && max != 0) {
			if (userMin.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(-min,userMin.first, userMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(-min, userMin.first, userMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			userMax.second += min;
			userMin.second = 0;
		}
		else if (-min > max  && min != 0 && max != 0) {
			if (userMin.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(max, userMin.first, userMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(max, userMin.first, userMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			userMin.second += max;
			userMax.second = 0;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= gestionnaireUtilisateurs_->getNombreElements() - 1) {
			calcul = false;
		}
	}

}

// Methode d'affichage
// TODO : À modifier :
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	for (int i = 0; i < groupe.gestionnaireUtilisateurs_->getNombreElements(); i++) {
		os << "\t- " << *groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first;
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (unsigned int i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}

	os << endl;
	return os;
}
