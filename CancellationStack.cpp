#include "CancellationStack.h"
#include <iostream>

using namespace std;

CancellationStack::CancellationStack()
{
    top = nullptr;
}

void CancellationStack::push(Reservation reservation)
{
    Node* newNode = new Node(reservation);

    newNode->next = top;

    top = newNode;
}

Reservation CancellationStack::pop()
{
    if (top == nullptr)
    {
        cout << "No cancellations to undo" << endl;

        return Reservation(-1, -1, "", "", "");
    }

    Node* temporary = top;

    Reservation reservation = temporary->reservation;

    top = top->next;

    delete temporary;

    return reservation;
}

Reservation CancellationStack::getTop()
{
    if (top == nullptr)
    {
        cout << "Cancellation history is empty" << endl;

        return Reservation(-1, -1, "", "", "");
    }

    return top->reservation;
}

bool CancellationStack::isEmpty()
{
    return top == nullptr;
}

void CancellationStack::displayCancellationHistory()
{
    if (top == nullptr)
    {
    cout << "Cancellation history is empty" << endl;
    return;
    }
    Node* current = top;

    while (current != nullptr)
    {
        cout << "Reservation ID: "
             << current->reservation.getReservationID() << endl;

        cout << "Student ID: "
             << current->reservation.getStudentID() << endl;

        cout << "Student Name: "
             << current->reservation.getStudentName() << endl;

        cout << "Resource ID: "
             << current->reservation.getResourceID() << endl;

        cout << "Reservation Date: "
             << current->reservation.getReservationDate() << endl;

        cout << endl;

        current = current->next;
    }
}