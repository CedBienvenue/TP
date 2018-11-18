/*
	Fichier : foncteur.h

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 18 novembre 2018
*/

/********************************************
*
* Titre: Travail pratique #5 - foncteur.h
* Date: 18 Novembre 2018
* Auteur: C�drik Bienvenue (1894296) & Mohamed Khairallah Gharbi (1837067)
*
*******************************************/
#ifndef FONCTEUR_H
#define FONCTEUR_H

#include <map>

class AjouterDepense {

public:
	//Constructeur
	AjouterDepense(vector<Depense*>& conteneur) : conteneur_(conteneur) {};
	vector<Depense*>& operator()(Depense* depense) {
		conteneur_.push_back(depense);
		return conteneur_;
	}

private:
	vector<Depense*>& conteneur_;
};

class AjouterUtilisateur {
public:
	//Constructeur
	AjouterUtilisateur(map<Utilisateur*, double>& conteneur) : conteneur_(conteneur) {};
	map<Utilisateur*, double>& operator()(Utilisateur* utilisateur) {
		conteneur_.insert(make_pair(utilisateur, 0));
		return conteneur_;
	}

private:
	map<Utilisateur*, double>& conteneur_;
};


class FoncteurIntervalle{
public:
	//Constructeur
	FoncteurIntervalle(double borneInf, double borneSup) : borneInf_(borneInf), borneSup_(borneSup) {};
	bool operator()(pair<Utilisateur*, double> p) {
		return p.second >= borneInf_ && p.second <= borneSup_;
	}

private:
	double borneInf_, borneSup_;
};

#endif // !FONCTEUR_H
