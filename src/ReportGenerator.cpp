#include "ReportGenerator.h"
#include <iostream>

void ReportGenerator::resourceUtilization(const std::vector<Resource>& resources,const ReservationList& activeReservations) const
{
    if (resources.size() == 0)
    {
        std::cout << "No resources available." << std::endl;
        return;
    }
    std::cout << "Resource Utilization Report" << std::endl;

    for (int i = 0; i < resources.size(); i++)
    {
        int count = activeReservations.countForResource(resources[i].getResourceID());

        std::cout << "Resource " << resources[i].getResourceID()  
                  << " (" << resources[i].getName()<< "): "
                  << count << " reservations." << std::endl;

    }
}