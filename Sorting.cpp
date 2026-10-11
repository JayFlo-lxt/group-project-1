#include "Sorting.h"

void sortRessourcesByName(stdd::vector<Resource>& resources)
{
  if(resources.empty())
{
return;
}
mergeSort (resources, 0, resources.size() -1);
}
