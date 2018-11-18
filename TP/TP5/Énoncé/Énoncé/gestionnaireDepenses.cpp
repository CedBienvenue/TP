#include "gestionnaireDepenses.h"

#include <algorithm>
#include <functional>


double GestionnaireDepenses::getTotalDepenses() const
{
	double totalDepense = 0.0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); ++it)
	{
		totalDepense += (*it)->getMontant();
	}
	return totalDepense;

}