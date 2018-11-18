/*
	Fichier : gestionnaireGenerique.h

	Fait par :  Cedrik Bienvenue (1894296)
				Mohamed Khairallah Gharbi (1837067)
	Date de derniere modification : 18 novembre 2018
*/

/********************************************
*
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 18 Novembre 2018
* Auteur: Cédrik Bienvenue (1894296) & Mohamed Khairallah Gharbi (1837067)
*
*******************************************/
#ifndef GESTIONNAIREGENERIQUE_H
#define GESTIONNAIREGENERIQUE_H

template<typename T, typename C, typename D, typename FoncteurAjouter>
class GestionnaireGenerique {
public:
	// Methode qui retourne le conteneur
	C getConteneur() const{ 
		return conteneur_; 
	}

	// Methode qui ajoute un element dans le conteneur
	void ajouter(T t) {
		FoncteurAjouter foncteur = FoncteurAjouter(conteneur_);
		foncteur(t); 
	}

	// Methode qui retourne le nombre d'element dans le conteneur
	int getNombreElements() const { return conteneur_.size(); }

	// Methode qui retourne un element du conteneur selon l'index passe en parametre
	D getElementParIndex(int i) const {
		
		auto it = conteneur_.begin();
		for (int j = 0; j < i; j++)
		{
			it++;
		}
		return *it;
	}

protected:
	C conteneur_;
};

#endif // !GESTIONNAIREGENERIQUE_H