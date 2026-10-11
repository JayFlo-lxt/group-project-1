#include "Sorting.h"

void sortRessourcesByName(stdd::vector<Resource>& resources)
{
  if(resources.empty())
{
return;
}
mergeSort (resources, 0, resources.size() -1);
}

void mergeSort(
std::vector<Resource>& resources)
int left,
int right,
)
  {
    if(left<right)
    {  
    int middle = left+ (right-left)/2;
    mergeSort (resources, left, ,middle);
    mergeSort (resources, middle + 1, right);
    mergeSort (resources, left, middle, right);
    }
}

