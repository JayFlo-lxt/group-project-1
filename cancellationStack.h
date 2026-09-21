#include "Reservation.h"

class CancellationStack
{
private:
    struct Node
    {
        Reservation reservation;
        Node* next;
    };

    Node* top;

public:
    CancellationStack();

    void push(Reservation reservation);
    Reservation pop();
    Reservation getTop();
    int isEmpty();
    void displayCancellationHistory();
};