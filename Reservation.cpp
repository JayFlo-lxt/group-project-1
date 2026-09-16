#include "Reservation.h"

Reservation :: Reservation(int resID, int stuID, std::string stuName, std::string resResourceID, std::string resDate)
{
    reservationID = resID;
    studentID = stuID;
    studentName = stuName;
    resourceID = resResourceID;
    reservationDate = resDate;
}
    int Reservation :: getReservationID()
    {
        return reservationID;
    }
    int Reservation :: getStudentID()
    {
        return studentID;
    }
    std::string Reservation :: getStudentName()
    {
        return studentName;
    }
    std::string Reservation :: getResourceID()
    {
        return resourceID;
    }
    std::string Reservation :: getReservationDate()
    {
        return reservationDate;
    }

