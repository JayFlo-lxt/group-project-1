#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include <vector>
#include "Resource.h"
#include "ReservationList.h"

class ReportGenerator 
{
public:
    void resourceUtilization(const std::vector<Resource>& resources,
                             const ReservationList& activeReservations) const;
};

#endif 