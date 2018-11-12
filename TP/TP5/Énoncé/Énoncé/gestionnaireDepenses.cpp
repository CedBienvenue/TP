#include "gestionnaireDepenses.h"

#include <algorithm>
#include <functional>


double GestionnaireDepenses::getTotalDepenses() const
{
	double totalDepense = 0.0;
	vector<Depense*>::iterator end = getConteneur().end();
	for (vector<Depense*>::iterator it = getConteneur().begin(); it != end; ++it)
	{
		totalDepense += (*it)->getMontant();
	}
	/*for (int i = 0; i < getNombreElements(); i++)
	{
		totalDepense += getElementParIndex(i)->getMontant();
	}*/
	return totalDepense;

}