#include "Reservation.h"
#include <iostream>
#include "Reservation.h"
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
        current->data.display();
        current = current->next;
    }
}

bool ReservationList::isEmpty() const {
    return head == nullptr;
}