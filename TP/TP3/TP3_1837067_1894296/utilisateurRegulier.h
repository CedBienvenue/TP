/*	Fichier : utilisateurRegulier.h

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification :21 Octobre 2018

*/
/********************************************
* Titre: Travail pratique #3 - utilisateurRegulier.h
* Date premiere version : 2 octobre 2018
* Auteur: David Dratwa
*******************************************/
#ifndef UTILISATEUR_REGULIER_H
#define UTILISATEUR_REGULIER_H

#include "utilisateur.h"

class UtilisateurRegulier : public Utilisateur {
public : 

	//constructeurs 
	UtilisateurRegulier(const string& nom = ""); 
	UtilisateurRegulier(const Utilisateur& utilisateur); 

	

	//getters
	bool estGroupe() const; 

	virtual string getNom() const;
	virtual double getInteret() const;
	virtual double getTotalDepenses() const;
	virtual TypeUtilisateur getType() const;
	virtual vector<Depense*> getDepenses() const;
	virtual unsigned int getNombreDepenses() const;

	//setters
	void setEtatGroupe(bool etat); 


	//surcharge
	virtual UtilisateurRegulier& operator=(Utilisateur* utilisateur);
	friend ostream& operator<< (ostream& os, const UtilisateurRegulier& utilisateur); 
private :
	bool estGroupe_; 
	
};

#endif // !UTILISATEUR_REGULIER_H
