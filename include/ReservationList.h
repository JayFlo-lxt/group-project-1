#ifndef RESERVATIONLIST_H
#define RESERVATIONLIST_H

#include "Reservation.h"

struct ReservationNode
{
    Reservation data;
    ReservationNode* next;

    ReservationNode(const Reservation& res)
        : data(res), next(nullptr)
    { 
    }
};

class ReservationList
{
public:
    Reservation();
    ~ReservationList();

    void insertReservation(const Reservation& res);
    bool removeReservation(int reservationID);
    ReservationNode* traverse(int reservationID) const;
    void displayReservations() const;
    bool isEmpty() const 

private:
    ReservationNode* head;
};

#endif