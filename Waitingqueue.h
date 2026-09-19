#include "Reservation.h"

class WaitingQueue
{
private:
    struct Node
    {
        Reservation reservation;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    WaitingQueue();

    void enqueue(Reservation reservation);
    Reservation dequeue();
    Reservation getFront();
    int isEmpty();
    void displayWaitingList();
};