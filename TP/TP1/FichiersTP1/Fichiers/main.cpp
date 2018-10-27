/////////////////////////////////////////////////////////////////////////////////////////////
////
//// Nom: Cédrik Bienvenue (1894296) et Mohamed Khairallah Gharbi (1837067)
//// Description: Programme qui permet de lister les dépenses de chaque utilisateur lors d'un événement.
////			  Il permet aussi de faire les comptes pour chaque membre et ainsi transférer l'argent pour 
////			  équilibrer ces comptes.
//// Date: 24 Septembre 2018
////
//// Réponse aux questions :
//// 1- Q: Quel est le lien (agrégation ou composition) entre les classes Groupe et Transfert ?
////    R: Composition, car la classe Groupe est composé de transfert entre les utilisateurs.
////	   Aussi, si on détruit un objet de la classe Groupe, l'objet transfert sera détruit aussi.
////
//// 2- Q: Quel effet aura une méthode si elle a un const ?
////    R: Cela indique au compilateur qu'il ne peut pas modifier l'état de l'objet, simplement lire l'information.
////
/////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "groupe.h"

using namespace std; 

int main(int argc, const char * argv[]) {
    cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************" << endl;
    // Creer un evenement pour  6 depenses et 4 utilisateurs.
	Groupe groupe("PolyPub", 6, 4);
    
    // Creer 5 utlisateurs.
	Utilisateur u1("u1");
	Utilisateur u2("u2");
	Utilisateur u3("u3");
	Utilisateur u4("u4");
	Utilisateur u5("u5");
    //Creer 7 dépenses.
	Depense d1("d1", 200.0);
	Depense d2("d2", 10.0);
	Depense d3("d3", 50.0);
	Depense d4("d4", 50.0);
	Depense d5("d5", 200.0);
	Depense d6("d6", 50.0);
	Depense d7("d7", 60.0);
    
    //ajouter les utilisateurs a l'evenement
	groupe.ajouterUtilisateur(&u1);
	groupe.ajouterUtilisateur(&u2);
	groupe.ajouterUtilisateur(&u3);
	groupe.ajouterUtilisateur(&u4);
	groupe.ajouterUtilisateur(&u5);
    //ajouter les depenses a l'evenement
	groupe.ajouterDepense(&d1, &u1);
	groupe.ajouterDepense(&d2, &u2);
	groupe.ajouterDepense(&d3, &u3);
	groupe.ajouterDepense(&d4, &u4);
	groupe.ajouterDepense(&d5, &u5);
	groupe.ajouterDepense(&d6, &u1);
	groupe.ajouterDepense(&d7, &u1);
    //calculer le total de l'evenement et de chaque utilisateur
	groupe.calculerTotalDepenses();
    //Afficher event
	groupe.afficherGroupe();
    
    //Equilibrer les comptes
	groupe.equilibrerComptes();
    //Afficher l'évenement
	groupe.afficherGroupe();
	cin.get();
    //terminer le programme correctement
	return 0;
}
