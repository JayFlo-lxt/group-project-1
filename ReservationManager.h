#pragma once
#include "Reservation.h"
#include "Resource.h"
#include <vector>
#include "ReservationList.h"
#include "WaitingQueue.h"
#include "CancellationStack.h"


class ReservationManager
{
    private:

    public:
        int findResource(const std::vector<Resource>& resources, const std::string& resourceID);
        bool isResourceAvailable(const std::vector<Resource>& resources, const std::string& resourceID);

        bool createReservation(std::vector<Resource>& resources, 
            ReservationList& activeReservations, 
            int resID, 
            int stuID, 
            const std::string& stuName,
            const std::string& resourceID, 
            const std::string& resDate,
            WaitingQueue& waitingQueue);

        bool cancelReservation(std::vector<Resource>& resources, 
            ReservationList& activeReservations, 
            int reservationID, 
            WaitingQueue& waitingQueue,
            CancellationStack& cancellationStack);

        bool undoCancellation(std::vector<Resource>& resources, 
            ReservationList& activeReservations, 
            CancellationStack& cancellationStack);

};