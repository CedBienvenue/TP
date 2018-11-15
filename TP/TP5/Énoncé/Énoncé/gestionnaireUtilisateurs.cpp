	/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "gestionnaireUtilisateurs.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"

using namespace std::placeholders;
using namespace std;
// Methode qui permet de mettre a jour un compte Utilisateur selon le montant passe en parametre
void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant) const {
	
	double montantReparti = montant / getNombreElements();
	map<Utilisateur*, double>::iterator end = getConteneur().end();
	for (map<Utilisateur*, double>::iterator it = getConteneur().begin(); it != end; ++it)
	{
		if (it->first == payePar)
		{
			it->second += (montant - montantReparti);
		}
		it->second -= montantReparti;
	}
}

// Methode qui permet de verifier si un Utilisateur est bien dans le groupe.
bool GestionnaireUtilisateurs::estExistant(Utilisateur* utilisateur) const {
	
	map<Utilisateur*, double>::iterator it = getConteneur().find(utilisateur);
	if (it != getConteneur().end())
	{
		return true;
	}
	return false;
}

// Methode d'acces
vector<double> GestionnaireUtilisateurs::getComptes() const {
	vector<double> compteUser;
	map<Utilisateur*, double>::iterator end = getConteneur().end();
	for (map<Utilisateur*, double>::iterator it = getConteneur().begin(); it != end; ++it)
	{
		compteUser.push_back(it->second);
	}
	return compteUser;
}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMax() const {
	double valeurMax = 0;
	pair<Utilisateur*, double> utilisateurMax;
	map<Utilisateur*, double>::iterator end = getConteneur().end();
	for (map<Utilisateur*, double>::iterator it = getConteneur().begin(); it != end; ++it)
	{
		if (it->second > valeurMax)
		{
			valeurMax = it->second;
			utilisateurMax = *it;
		}
	}
	return utilisateurMax;

}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMin() const {
	
	double valeurMin = 0;
	pair<Utilisateur*, double> utilisateurMin;

	map<Utilisateur*, double>::iterator end = getConteneur().end();
	for (map<Utilisateur*, double>::iterator it = getConteneur().begin(); it != end; it++)
	{
		if (it->second < valeurMin)
		{
			valeurMin = it->second;
			utilisateurMin = *it;
		}
	}
	return utilisateurMin;
}

Utilisateur* GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const {
	map<Utilisateur*, double>::iterator it;
	it = find_if(getConteneur().begin(), getConteneur().end(), bind(equal_to<pair<Utilisateur*, double>>(), _1, make_pair(utilisateur, montant)));
	if (it != getConteneur().end())
	{
		return (it++)->first;
	}
	return nullptr;
}

vector<pair<Utilisateur*, double>> GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const {
	vector<pair<Utilisateur*, double>> userEntre;
	map<Utilisateur*, double>::iterator end = getConteneur().end();
	copy_if(getConteneur().begin(), end, back_inserter(userEntre), FoncteurIntervalle(borneInf, borneSup));
	return userEntre;
}

// Methode de modification
GestionnaireUtilisateurs& GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p) {
	
	map<Utilisateur*, double>::iterator it;
	it = getConteneur().find(p.first);
	if (it != getConteneur().end())
	{
		it->second = p.second;
		return *this;
	}
	return *this;
}