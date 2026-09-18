#ifndef RESERVATION_H
#define RESERVATION_H
 
#include <string>
 
// Represent single reservation record
class Reservation {
public:
    Reservation();
    Reservation(const std::string& reservationID, const std::string& studentID,
                const std::string& studentName, const std::string& resourceID,
                const std::string& date);
 
    std::string getReservationID() const;
    std::string getStudentID() const;
    std::string getStudentName() const;
    std::string getResourceID() const;
    std::string getDate() const;
 
    void display() const;
 
private:
    std::string reservationID;
    std::string studentID;
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
    ~ReservationList(); // frees every node avoids memory leaks
 
    // Inserts a new reservation at the head. O(1).
    void insertReservation(const Reservation& res);
 
    // Removes a reservation by ID. O(n) must traverse to find it.
    // Returns true if found and removed, false otherwise.
    bool removeReservation(const std::string& reservationID);
 
    // Returns a pointer to the reservation with this ID, or nullptr if not found.
    // Used internally by removeReservation and can be reused for searching.
    ReservationNode* traverse(const std::string& reservationID) const;
 
    // Prints every active reservation.
    void displayReservations() const;
 
    // Returns true if the list has no reservations.
    bool isEmpty() const;
 
private:
    ReservationNode* head;
};
 
#endif // RESERVATION_H