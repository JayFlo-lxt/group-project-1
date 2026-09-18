#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

// Represents a single reservation record
class Reservation {
public:
    Reservation();
    Reservation(int reservationID, int studentID,
                const std::string& studentName, const std::string& resourceID,
                const std::string& date);

    int getReservationID() const;
    int getStudentID() const;
    std::string getStudentName() const;
    std::string getResourceID() const;
    std::string getReservationDate() const;

    void display() const;

private:
    int reservationID;
    int studentID;
    std::string studentName;
    std::string resourceID;
    std::string date;
};

// A single node in the singly linked list of active reservations
struct ReservationNode {
    Reservation data;
    ReservationNode* next;

    ReservationNode(const Reservation& res) : data(res), next(nullptr) {}
};

// Manages the linked list of active reservations.
// Required operations: insert, remove, traverse, display.
class ReservationList {
public:
    ReservationList();
    ~ReservationList();

    void insertReservation(const Reservation& res);
    bool removeReservation(int reservationID);
    ReservationNode* traverse(int reservationID) const;
    void displayReservations() const;
    bool isEmpty() const;

private:
    ReservationNode* head;
};

#endif // RESERVATION_H