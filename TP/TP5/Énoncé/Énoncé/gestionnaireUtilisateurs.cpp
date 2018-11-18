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
void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant){
	
	double montantReparti = montant / getNombreElements();
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		if (it->first == payePar)
		{
			it->second += (montant - montantReparti);
		}
		else
		{
			it->second -= montantReparti;
		}
	}
}

// Methode qui permet de verifier si un Utilisateur est bien dans le groupe.
bool GestionnaireUtilisateurs::estExistant(Utilisateur* utilisateur) const {
	
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		if (it->first == utilisateur)
		{
			return true;
		}
	}
	return false;
}

// Methode d'acces
vector<double> GestionnaireUtilisateurs::getComptes() const {
	vector<double> compteUser;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		compteUser.push_back(it->second);
	}
	return compteUser;
}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMax() const {
	auto it = max_element(conteneur_.begin(), conteneur_.end(), 
		[](pair<Utilisateur*, double> i, pair<Utilisateur*, double> j) -> bool {return i.second < j.second; });
	return (pair<Utilisateur*, double>&)*it;
}
	
pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMin() const {
	auto it = min_element(conteneur_.begin(), conteneur_.end(),
		[](pair<Utilisateur*, double> i, pair<Utilisateur*, double> j) -> bool {return i.second < j.second; });
	return (pair<Utilisateur*, double>&)*it;
}

Utilisateur* GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const {
	map<Utilisateur*, double>::const_iterator it;
	it = find_if(conteneur_.begin(), conteneur_.end(), bind(equal_to<pair<Utilisateur*, double>>(), _1, make_pair(utilisateur, montant)));
	if (it != conteneur_.end())
	{
		it++;
		return it->first;
	}
	return nullptr;
}

vector<pair<Utilisateur*, double>> GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const {
	vector<pair<Utilisateur*, double>> userEntre;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(userEntre), FoncteurIntervalle(borneInf, borneSup));
	return userEntre;
}

// Methode de modification
GestionnaireUtilisateurs& GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p) {
	
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
	{
		if (it->first == p.first)
		{
			it->second = p.second;
			return *this;
		}
	}
	return *this;
}