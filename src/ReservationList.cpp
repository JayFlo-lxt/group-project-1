#include "Reservation.h"
#include <iostream>
#include "ReservationList.h"


ReservationList::ReservationList() : head(nullptr) {}

ReservationList::~ReservationList() {
    ReservationNode* current = head;
    while (current != nullptr) {
        ReservationNode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void ReservationList::insertReservation(const Reservation& res) {
    ReservationNode* newNode = new ReservationNode(res);
    newNode->next = head;
    head = newNode;
}

ReservationNode* ReservationList::traverse(int reservationID) const {
    ReservationNode* current = head;
    while (current != nullptr) {
        if (current->data.getReservationID() == reservationID) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

bool ReservationList::removeReservation(int reservationID) {
    ReservationNode* current = head;
    ReservationNode* previous = nullptr;

    while (current != nullptr) {
        if (current->data.getReservationID() == reservationID) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

void ReservationList::displayReservations() const {
    if (head == nullptr) {
        std::cout << "No active reservations." << std::endl;
        return;
    }
    ReservationNode* current = head;
    while (current != nullptr) {
        std::cout << "Reservation ID: "
          << current->data.getReservationID() << std::endl;

        std::cout << "Student ID: "
          << current->data.getStudentID() << std::endl;

        std::cout << "Student Name: "
          << current->data.getStudentName() << std::endl;

        std::cout << "Resource ID: "
          << current->data.getResourceID() << std::endl;

        std::cout << "Reservation Date: "
          << current->data.getReservationDate() << std::endl;

        std::cout << std::endl;
        current = current->next;
    }
}

bool ReservationList::isEmpty() const {
    return head == nullptr;
}

void ReservationList::searchByStudent(int studentID) const
{
    ReservationNode* current = head;
    int found = 0;

    while (current != nullptr)
    {
        if (current->data.getStudentID() == studentID )
    {
        std::cout << "Reservation ID:  " << current->data.getReservationID()
             << " | Student: " << current->data.getStudentName()
             << " | Resource: " << current->data.getResourceID()
             << " | Date: " << current->data.getReservationDate() << std::endl;
        found = found + 1;
    }
    current = current-> next;
}

if (found == 0)
{
 std::cout << "No reservations found for student " << studentID << "." << std::endl;
}

}

int ReservationList::countForResource(const std::string& resourceID) const {
    ReservationNode* current = head;
    int count = 0;
    while (current != nullptr) 
    {
        if (current->data.getResourceID() == resourceID) 
        {   
            count = count + 1;
        }
        current = current->next;
    }
    return count;
}
