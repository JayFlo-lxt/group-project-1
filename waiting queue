
#include "WaitingQueue.h"
#include <iostream>

using namespace std;

WaitingQueue::WaitingQueue()
{
    front = nullptr;
    rear = nullptr;
}

void WaitingQueue::enqueue(Reservation reservation)
{
    Node* newNode = new Node(reservation);

    if (front == nullptr)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

Reservation WaitingQueue::dequeue()
{
    if (front == nullptr)
    {
        cout << "Waiting list is empty" << endl;

        return Reservation(-1, -1, "", "", "");
    }

    Node* temporary = front;

    Reservation reservation = temporary->reservation;

    front = front->next;

    delete temporary;

    if (front == nullptr)
    {
        rear = nullptr;
    }

    return reservation;
}

Reservation WaitingQueue::getFront()
{
    if (front == nullptr)
    {
        cout << "Waiting list is empty" << endl;

        return Reservation(-1, -1, "", "", "");
    }

    return front->reservation;
}

bool WaitingQueue::isEmpty()
{
    return front == nullptr;
}

void WaitingQueue::displayWaitingList()
{
    Node* current = front;

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
