/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#ifndef GESTIONNAIREGENERIQUE_H
#define GESTIONNAIREGENERIQUE_H

template<typename T, typename C, typename D, typename FoncteurAjouter>
class GestionnaireGenerique {
public:
	C getConteneur() const { return conteneur_; }
	void ajouter(T t) {
		FoncteurAjouter foncteur = FoncteurAjouter(conteneur_);
		foncteur(t&); // & � v�rifier
	}
	int getNombreElements() const { return conteneur_.size(); }
	D getElementParIndex(int i) const {
		if (i < getNombreElements())
		{
			auto iterator = conteneur_.begin() + i;
			return *iterator;
		}
		return nullptr;
	}

protected:
	C conteneur_;
};

#endif // !GESTIONNAIREGENERIQUE_H