/*
Fait par :  Cedrik Bienvenue (1894296)
Mohamed Khairallah Gharbi (1837067)
Date de derniere modification : 30 septembre 2018

*/

/*
 Réponse aux questions
 1. Q: Quelle est l’utilité de l’opérateur = et du constructeur par copie ?
	R: Ces deux fonctions permettent de copier les instances d'un objet existant. Lorsqu'ils sont définis, il remplace ceux défini par le compilateur.
 
 2. Q: Qu’est-ce qui différencie l’opérateur = du constructeur par copie ?
	R: Le constructeur par copie va copier les instances d'un objet existant, alors que l'opérateur = va assigner les instances à un nouvel objet.

*/
/********************************************
* Titre: Travail pratique #2 - main.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include <iostream>
#include "depense.h"
#include "utilisateur.h"
#include  "transfert.h"
#include "groupe.h"

using namespace std;

int main() {

	cout << "\t \tBienvenue sur you're mom " << endl << " *****************************************************" << endl;

	// Initialisation des depenses
	Depense* d1 = new Depense("Épicerie", 52, "IGA");
	Depense* d2 = new Depense("Gaz1", 42.5, "Provigo");
	Depense* d3 = new Depense("Gaz2", 44, "Jean-drapeau");
	Depense* d4 = new Depense("Billet", 736.8, "Vieux port");
	Depense* d5 = new Depense("Parking", 30, "Metro");
	Depense* d6 = new Depense("Airbnb", 260, "Desjardins");
	Depense* d7 = new Depense("alcool", 105, "YourMom");
	// Exemple d'utilisation du constructeur par copie et de l'operateur d'assignation
	/*Depense* d7 = new Depense(*d5);
	d7->setNom("d7");
	d7->setLieu("Maisonnee");

	Depense* d8 = new Depense();
	*d8 = *d1;
	d8->setNom("d8");
	d8->setLieu("Banque scotia");*/

	// Initialisation des utilisateurs
	Utilisateur* u1 = new Utilisateur("Cédrik");
	Utilisateur* u2 = new Utilisateur("Math");
	Utilisateur* u3 = new Utilisateur("Ric");
	Utilisateur* u4 = new Utilisateur("Dom");

	// Initialisation du groupe
	Groupe* groupe = new Groupe("vacances");

	// Ajout des utilisateurs et des depenses au groupe
	((((*groupe += u1) += u2) += u3) += u4);

	groupe->ajouterDepense(d1, u1).ajouterDepense(d2, u1).ajouterDepense(d4, u2).ajouterDepense(d3, u3).ajouterDepense(d7, u3)
		.ajouterDepense(d5, u3).ajouterDepense(d6, u4);
	// Equilibrage des comptes
	cout << *groupe;
	groupe->equilibrerComptes();
	cout << *groupe;

	// TODO: Terminez le programme correctement
	cin.get();
	return 0;
}
