#include "Reservation.h"

Reservation::Reservation(
int resID,
int stuID,
std::string stuName,
std::string resResourceID,
std::string resDate)
: reservationID(resID),
studentID(stuID),
studentName(stuName),
resourceID(resResourceID),
reservationDate(resDate)
{
}

int Reservation::getReservationID() const
{
return reservationID;
}

int Reservation::getStudentID() const
{
return studentID;
}

std::string Reservation::getStudentName() const
{
return studentName;
}

std::string Reservation::getResourceID() const
{
return resourceID;
}

std::string Reservation::getReservationDate() const
{
return reservationDate;
}