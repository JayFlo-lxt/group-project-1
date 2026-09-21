#pragma once
#include <string>

class Reservation 
{
    private:
        int reservationID;
        int studentID;
        std::string studentName;
        std::string resourceID;
        std::string reservationDate;

        public:
            Reservation(int resID, int stuID, std::string stuName, std::string resResourceID, std::string resDate);

            int getReservationID();
            int getStudentID();
            std::string getStudentName();
            std::string getResourceID();
            std::string getReservationDate();
};  
