#include "ReservationManager.h"
int ReservationManager::findResource(const std::vector<Resource>& resources, const std::string& resourceID)  
{ 
    for (int i = 0; i<resources.size(); i++)
    {
        if (resources[i].getResourceID() == resourceID)
        {
            return i;
        }
    }
      return -1;
}
bool ReservationManager::isResourceAvailable(const std::vector<Resource>& resources, const std::string& resourceID)
{
    int index = findResource(resources, resourceID);

    if (index != -1)
    {
        return resources[index].isAvailable();
    }
    return false;
}
bool ReservationManager::createReservation(std::vector<Resource>& resources, 
            ReservationList& activeReservations, 
            int resID, 
            int stuID, 
            const std::string& stuName,
            const std::string& resourceID, 
            const std::string& resDate,
            WaitingQueue& waitingQueue )
{
    int index = findResource(resources, resourceID);

    if (index == -1)
    {
        return false;
    }

     if (activeReservations.traverse(resID) != nullptr)
    {
        return false;
    }

    if (!isResourceAvailable(resources, resourceID))
    {
        waitingQueue.enqueue(Reservation(resID, stuID, stuName, resourceID, resDate));

        return false;
    }

    activeReservations.insertReservation(Reservation(resID, stuID, stuName, resourceID, resDate));
   
    resources[index].setAvailable(false);
    
    return true;

    
}
bool ReservationManager::cancelReservation(std::vector<Resource>& resources, 
            ReservationList& activeReservations, 
            int reservationID, 
            WaitingQueue& waitingQueue,
            CancellationStack& cancellationStack)
{
    ReservationNode* node = activeReservations.traverse(reservationID);

    if (node == nullptr)
    {
        return false;
    }

    Reservation cancelledReservation = node->data;
    std::string resourceID = cancelledReservation.getResourceID();

    activeReservations.removeReservation(reservationID);

    cancellationStack.push(cancelledReservation);

    Reservation waitingReservation = waitingQueue.dequeueForResource(resourceID);

    if(waitingReservation.getReservationID() != -1)
    {
        activeReservations.insertReservation(waitingReservation);
    }
    else
    {
        int resourceIndex = findResource(resources, resourceID);
        if (resourceIndex != -1)
        {
            resources[resourceIndex].setAvailable(true);
        }
    }
    return true;
}
 bool ReservationManager::undoCancellation(std::vector<Resource>& resources, 
            ReservationList& activeReservations, 
            CancellationStack& cancellationStack)
{
    if (cancellationStack.isEmpty())
    {
        return false;
    }

    Reservation cancelledReservation = cancellationStack.getTop();

    std::string resourceID = cancelledReservation.getResourceID();

    int index = findResource(resources, resourceID);

    if (index == -1)
    {
        return false;
    }

    if (!isResourceAvailable(resources, resourceID))
    {
        return false;
    }

    cancellationStack.pop();

    activeReservations.insertReservation(cancelledReservation);

    resources[index].setAvailable(false);

    return true;
}