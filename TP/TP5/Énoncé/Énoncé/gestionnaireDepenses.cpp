#include "gestionnaireDepenses.h"

#include <algorithm>
#include <functional>


double GestionnaireDepenses::getTotalDepenses() const
{
	double totalDepense = 0.0;
	for (int i = 0; i < getNombreElements(); i++)
	{
		totalDepense += getElementParIndex(i)->getMontant();
	}
}