#include "gestionnaireDepenses.h"

#include <algorithm>
#include <functional>

//vector<Depense*> GestionnaireDepenses::getDepenses() const
//{
//	return depenses_;
//}
//
//int GestionnaireDepenses::getNombreDepenses() const
//{
//	return depenses_.size();
//}
//
//int GestionnaireDepenses::getIndexDe(Depense * depense) const
//{
//	int index = -1;
//	for (int i = 0; i < depenses_.size(); i++) {
//		if (depenses_[i] == depense) {
//			index = i;
//			break;
//		}
//		i++;
//	}
//	return index;
//}
//
//Depense * GestionnaireDepenses::getDepenseParIndex(int i) const
//{
//	return depenses_[i];
//}

double GestionnaireDepenses::getTotalDepenses() const
{
	return 0.0;
}

//GestionnaireDepenses & GestionnaireDepenses::ajouterDepense(Depense * depense)
//{
//	depenses_.push_back(depense);
//	return *this;
//}
