#include "Sorting.h"

void sortResourcesByName(std::vector<Resource>& resources)
{
  if(resources.empty())
{
return;
}
mergeSort (resources, 0, resources.size() -1);
}

void mergeSort(
  std::vector<Resource>& resources,
  int left,
  int right
)
  {
    if(left<right)
    {  
    int middle = left+ (right-left)/2;
    mergeSort (resources, left, middle);
    mergeSort (resources, middle + 1, right);
    merge (resources, left, middle, right);
    }
}

void merge(
  std::vector<Resource>& resources,
  int left,
  int middle,
  int right
)

{
  int leftSize = middle - left + 1;
  int rightSize = right - middle;

  std::vector<Resource> leftHalf;
  std:: vector<Resource> rightHalf;

for(int i=0; i < leftSize; i++)
  {
    leftHalf.push_back(resources[left+i]);
  }
for(int j=0; j < rightSize; j++)
  {
    rightHalf.push_back(resources[middle+1+j]);
  }
  int i=0;
  int j=0;
  int k=left;

while(i<leftSize && j<rightSize)
  {
    if(leftHalf[i].getName() <= rightHalf[j].getName())
      {
        resources[k] = leftHalf[i];
        i++;
      }
    else
      {
        resources[k] = rightHalf[j];
        j++;
      }
        k++;
  }

while(i<leftSize)
  {
    resources[k] = leftHalf[i];
    i++;
    k++;
  }
while(j<rightSize)
  {
    resources[k] = rightHalf[j];
      j++;
      k++;
  }
}

