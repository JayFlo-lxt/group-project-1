#pragma once
#include "Reservation.h"

class WaitingQueue
{
private:
    struct Node
    {
        Reservation reservation;
        Node* next;

        Node(const Reservation& res)
        : reservation(res), next(nullptr)
        {
        }
    };

    Node* front;
    Node* rear;

public:
    WaitingQueue();

    void enqueue(Reservation reservation);
    Reservation dequeue();

    Reservation dequeueForResource(const std::string& resourceID);
    Reservation getFront();
    bool isEmpty();
    void displayWaitingList();
};