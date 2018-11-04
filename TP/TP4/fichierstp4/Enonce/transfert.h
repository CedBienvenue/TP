/*
	Fichier : transfert.h

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 4 novembre 2018
*/

/********************************************
* Titre: Travail pratique #4 - transfert.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#ifndef TRANSFERT_H
#define TRANSFERT_H

#include "utilisateur.h"
#include "utilisateurPremium.h"

#include <iostream>

#include <stdio.h>

class Transfert {
public:
	// Constructeurs
	Transfert();
	Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur_);

	//Destructeurs :
	~Transfert(); 
	// Méthodes d'accès
	Utilisateur* getExpediteur() const;
	Utilisateur* getReceveur() const;
	double getMontant() const;
	// TODO
	virtual double getFraisTransfert() const = 0; // Methode virtuelle pure.

	// Méthodes d'affichage
	void setMontant(double montant);
	void setExpediteur(Utilisateur* expediteur);
	void setReceveur(Utilisateur* receveur);

	// TODO
	void effectuerTransfert();

	friend ostream& operator<<(ostream& os, const Transfert& transfert);

protected:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;
};

#endif