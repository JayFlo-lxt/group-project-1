#include "Reservation.h"
#include <iostream>

// ---------------- Reservation ----------------

Reservation::Reservation()
    : reservationID(""), studentID(""), studentName(""), resourceID(""), date("") {}

Reservation::Reservation(const std::string& reservationID, const std::string& studentID,
                          const std::string& studentName, const std::string& resourceID,
                          const std::string& date)
    : reservationID(reservationID), studentID(studentID), studentName(studentName),
      resourceID(resourceID), date(date) {}

std::string Reservation::getReservationID() const { return reservationID; }
std::string Reservation::getStudentID() const { return studentID; }
std::string Reservation::getStudentName() const { return studentName; }
std::string Reservation::getResourceID() const { return resourceID; }
std::string Reservation::getDate() const { return date; }

void Reservation::display() const {
    std::cout << "Reservation " << reservationID
              << " | Student: " << studentName << " (" << studentID << ")"
              << " | Resource: " << resourceID
              << " | Date: " << date
              << std::endl;
}

// ---------------- ReservationList (linked list) ----------------

ReservationList::ReservationList() : head(nullptr) {}

// Frees every node to avoid memory leaks
ReservationList::~ReservationList() {
    ReservationNode* current = head;
    while (current != nullptr) {
        ReservationNode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

// Insert at head. O(1).
void ReservationList::insertReservation(const Reservation& res) {
    ReservationNode* newNode = new ReservationNode(res);
    newNode->next = head;
    head = newNode;
}

// O(n) — searches the chain for a matching ID
ReservationNode* ReservationList::traverse(const std::string& reservationID) const {
    ReservationNode* current = head;
    while (current != nullptr) {
        if (current->data.getReservationID() == reservationID) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// O(n) — must find the node before it can be removed
bool ReservationList::removeReservation(const std::string& reservationID) {
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