
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
Reservation WaitingQueue::dequeueForResource(
    const std::string& resourceID)
{
    Node* current = front;
    Node* previous = nullptr;

    while (current != nullptr)
    {
        if (current->reservation.getResourceID() == resourceID)
        {
            Reservation savedReservation = current->reservation;

            if (current == front)
            {
                front = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            if (current == rear)
            {
                rear = previous;
            }

            delete current;

            if (front == nullptr)
            {
                rear = nullptr;
            }

            return savedReservation;
        }
        previous = current;
        current = current->next;
    }
    return Reservation(-1, -1, "", "", "");
}
void WaitingQueue::displayWaitingListStatistics()
{
    Node* current = front;
    int totalWaiting = 0;

    cout << "\n===== WAITING LIST STATISTICS =====" << endl;

    if (front == nullptr)
    {
        cout << "The waiting list is empty." << endl;
        cout << "Total Students Waiting: 0" << endl;
        return;
    }

    while (current != nullptr)
    {
        string resourceID = current->reservation.getResourceID();
        int count = 0;
        bool alreadyCounted = false;

        Node* previous = front;

        while (previous != current)
        {
            if (previous->reservation.getResourceID() == resourceID)
            {
                alreadyCounted = true;
                break;
            }

            previous = previous->next;
        }

        if (!alreadyCounted)
        {
            Node* temp = current;

            while (temp != nullptr)
            {
                if (temp->reservation.getResourceID() == resourceID)
                {
                    count++;
                }

                temp = temp->next;
            }

            cout << "Resource ID: " << resourceID << endl;
            cout << "Students Waiting: " << count << endl;
            cout << "-----------------------------" << endl;
        }

        totalWaiting++;
        current = current->next;
    }

    cout << "Total Students Waiting: " << totalWaiting << endl;
    cout << "===================================" << endl;
}
// Linear Search
bool WaitingQueue::searchWaitingStudent(int studentID)
{
    Node* current = front;

    while (current != nullptr)
    {
        if (current->reservation.getStudentID() == studentID)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}