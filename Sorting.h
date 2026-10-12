#pragma once

#include <vector>
#include "Resource.h"

void merge(
std::vector<Resource>& resources,
int left, 
int middle, 
int right
);

void mergeSort(
std::vector<Resource>& resources,
int left,
int right
);

void sortResourcesByName(
std::vector<Resource>& resources
);