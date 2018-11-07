/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/


class AjouterDepense{

public:
	//Constructeur
	AjouterDepense(vector<Depense*> conteneur) : conteneur_(conteneur) {};
	vector<Depense*>& operator()(Depense*);

private:
	vector<Depense*> conteneur_;
};



class AjouterUtilisateur {
public:
	//Constructeur
	AjouterUtilisateur(map conteneur) : conteneur_(conteneur) {};
	map<Utilisateur*, double>& operator()(Utilisateur*);

private:
	map<Utilisateur*, double> conteneur_;
};


class FoncteurIntervalle{
public:
	//Constructeur
	FoncteurIntervalle(double borneInf, double borneSup) : borneInf_(borneInf), borneSup_(borneSup) {};
	bool operator()(pair<Utilisateur*, double>);

private:
	double borneInf_, borneSup_;
};



