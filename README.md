Url for Github: https://github.com/JayFlo-lxt/group-project-1

PROJECT DESCRIPTION:
The Campus Resource Reservation System is a C++ program that allows users to manage campus resources and reservations. The system can load resources from a file, create and cancel reservations, manage waiting lists, track cancellation history, and restore cancelled reservations.

DATA STRUCTURES USED:
* Linked List
* Queue
* Stack
* Vector

FILES: 
* main.cpp
* Reservation.h / Reservation.cpp
* ReservationManager.h / ReservationManager.cpp
* Resource.h / Resource.cpp
* ReservationList.h / ReservationList.cpp
* WaitingQueue.h / WaitingQueue.cpp
* CancellationStack.h / CancellationStack.cpp
* resources.txt

HOW TO COMPILE: 
g++ -std=c++17 main.cpp Reservation.cpp Resource.cpp ReservationList.cpp WaitingQueue.cpp CancellationStack.cpp ReservationManager.cpp -o campus_reservation

*ALL THE RESOURCES INFORMATION "including resouce numbers and names" ARE IN "resources.txt"

HOW TO RUN:
./campus_reservation