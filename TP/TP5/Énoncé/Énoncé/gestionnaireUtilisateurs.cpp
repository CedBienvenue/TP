/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "gestionnaireUtilisateurs.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"


// Methode qui permet de mettre a jour un compte Utilisateur selon le montant passe en parametre
void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant) const {

}

// Methode qui permet de verifier si un Utilisateur est bien dans le groupe.
bool GestionnaireUtilisateurs::estExistant(Utilisateur* utilisateur) const {
	
}

// Methode d'acces
vector<double> GestionnaireUtilisateurs::getComptes() const {

}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMax() const {

}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMin() const {

}

Utilisateur* GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur*, double montant) const {

}

vector<pair<Utilisateur*, double>> GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const {

}

// Methode de modification
GestionnaireUtilisateurs& GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p) {
	
}