# CAMPUS RESOURCE RESERVATION SYSTEM - USER DOCUMENTATION

PURPOSE: 
  This program allows users to manage campus resources and reservations. Users can create and cancel reservations, manage waiting lists, search reservations, sort resources, view reports, and track cancellations.

HOW TO RUN:

* COMPILE THE [PROGRAM USING:
  g++ -std=c++17 main.cpp Reservation.cpp Resource.cpp ReservationList.cpp WaitingQueue.cpp CancellationStack.cpp ReservationManager.cpp Sorting.cpp ReportGenerator.cpp -o campus_reservation

* RUN THE PROGRAM USING:
  ./campus_reservation

MAIN MENU:
  1. View Resources: Displays all resources and their current availability.
  2. Create Reservation: Enter a reservation ID, student ID, student name, resource ID, and reservation date. If the resource is available, the reservation is created. If the resource is unavailable, the request may be placed on the waiting list.
  3. Cancel Reservation: Enter the reservation ID to cancel. The cancelled reservation is stored in the cancellation history. If another student is waiting for the resource, the resource may be assigned to the next waiting student.
  4. View Active Reservations: Displays all currently active reservations.
  5. View Waiting List: Displays students currently waiting for unavailable resources.
  6. Undo Cancellation: Attempts to restore the most recently cancelled reservation if the resource is available.
  7. View Cancellation History: Displays cancelled reservations stored in the cancellation stack.
  8. Search Reservations by Student ID: Enter a Student ID. The program uses Linear Search to find active reservations associated with that student.
  9. Sort Resources by Name: Uses Merge Sort to arrange resources alphabetically by resource name.
  10. Generate Reports: Generates report including Active reservation, Resource Utilization, Waiting List Count, Most Requested Resource
  11. Exit: Ends the program.

ERROR HANDLING: 
  The program handles invalid menu choices and incorrect menu input. It also checks for invalid resource IDs, missing reservations, and unsuccessful cancellation or undo requests.

RESOURCE FILE:
  Resource information is stored in resources.txt. Users should enter valid resource IDs from this file when creating reservations.

DATA STRUCTURES AND ALGORITHM USED: 
  - Linked List — stores active reservations
  - Queue — manages the waiting list
  - Stack — stores cancellation history
  - Vector — stores resource information
  - Linear Search — searches reservations by Student ID
  - Merge Sort — sorts resources by name
