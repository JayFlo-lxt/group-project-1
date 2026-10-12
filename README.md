Url for Github: https://github.com/JayFlo-lxt/group-project-1

PROJECT DESCRIPTION:
The Campus Resource Reservation System is a C++ program that allows users to manage campus resources and reservations. The system can load resources from a file, create and cancel reservations, manage waiting lists, track cancellation history, and restore cancelled reservations. Now, the final system also supports searching, Merge Sort, reports, and improved error handling.

FEATURES:
- Search reservations by Student ID using Linear Search
- Sort resources by name using Merge Sort
- Active Reservations report
- Resource Utilization report
- Waiting-List Statistics
- Most Requested Resources (add once Noah finishes it)
- Invalid-input handling
  
DATA STRUCTURES USED:
* Linked List
* Queue
* Stack
* Vector
* Linear Search
* Merge Sort

FILES: 
* main.cpp
* Reservation.h / Reservation.cpp
* ReservationManager.h / ReservationManager.cpp
* Resource.h / Resource.cpp
* ReservationList.h / ReservationList.cpp
* WaitingQueue.h / WaitingQueue.cpp
* CancellationStack.h / CancellationStack.cpp
* Sorting.h / Sorting.cpp
* ReportGenerator.h / ReportGenerator.cpp
* resources.txt

HOW TO COMPILE: 
g++ -std=c++17 main.cpp Reservation.cpp Resource.cpp ReservationList.cpp WaitingQueue.cpp CancellationStack.cpp ReservationManager.cpp Sorting.cpp ReportGenerator.cpp -o campus_reservation

*ALL THE RESOURCES INFORMATION "including resouce numbers and names" ARE IN "resources.txt"

HOW TO RUN:
./campus_reservation
