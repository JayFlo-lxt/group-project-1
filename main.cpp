#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "Resource.h"
#include "Reservation.h"
#include "ReservationList.h"
#include "WaitingQueue.h"
#include "CancellationStack.h"
#include "ReservationManager.h"

int main()
{
    std::vector<Resource> resources =
        loadResourcesFromFile("resources.txt");

    ReservationList activeReservations;
    WaitingQueue waitingQueue;
    CancellationStack cancellationStack;
    ReservationManager manager;

    int choice = 0;

    while (choice != 8)
    {
        std::cout << "\nCampus Resource Reservation System\n";
        std::cout << "1. View Resources\n";
        std::cout << "2. Create Reservation\n";
        std::cout << "3. Cancel Reservation\n";
        std::cout << "4. View Active Reservations\n";
        std::cout << "5. View Waiting List\n";
        std::cout << "6. Undo Cancellation\n";
        std::cout << "7. View Cancellation History\n";
        std::cout << "8. Exit\n";

        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            displayAllResources(resources);
        }

        else if (choice == 2)
        {
            int resID;
            int stuID;
            std::string stuName;
            std::string resourceID;
            std::string resDate;

            std::cout << "Enter reservation ID: ";
            std::cin >> resID;

            std::cout << "Enter student ID: ";
            std::cin >> stuID;

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::cout << "Enter student name: ";
            std::getline(std::cin, stuName);

            std::cout << "Enter resource ID: ";
            std::cin >> resourceID;

            std::cout << "Enter reservation date: ";
            std::cin >> resDate;

            bool created = manager.createReservation(
                resources,
                activeReservations,
                resID,
                stuID,
                stuName,
                resourceID,
                resDate,
                waitingQueue
            );

            if (created)
            {
                std::cout
                    << "Reservation created successfully."
                    << std::endl;
            }
            else
            {
                std::cout
                    << "Reservation could not be created as an active reservation."
                    << std::endl;

                std::cout
                    << "It may have been placed on the waiting list or the request was invalid."
                    << std::endl;
            }
        }

        else if (choice == 3)
        {
            int reservationID;

            std::cout << "Enter reservation ID to cancel: ";
            std::cin >> reservationID;

            bool cancelled = manager.cancelReservation(
                resources,
                activeReservations,
                reservationID,
                waitingQueue,
                cancellationStack
            );

            if (cancelled)
            {
                std::cout
                    << "Reservation cancelled successfully."
                    << std::endl;
            }
            else
            {
                std::cout
                    << "Reservation not found."
                    << std::endl;
            }
        }

        else if (choice == 4)
        {
            activeReservations.displayReservations();
        }

        else if (choice == 5)
        {
            waitingQueue.displayWaitingList();
        }

        else if (choice == 6)
        {
            bool undone = manager.undoCancellation(
                resources,
                activeReservations,
                cancellationStack
            );

            if (undone)
            {
                std::cout
                    << "Cancellation undone successfully."
                    << std::endl;
            }
            else
            {
                std::cout
                    << "Unable to undo cancellation."
                    << std::endl;
            }
        }

        else if (choice == 7)
        {
            cancellationStack.displayCancellationHistory();
        }

        else if (choice == 8)
        {
            std::cout
                << "Exiting program..."
                << std::endl;
        }

        else
        {
            std::cout
                << "Invalid menu choice."
                << std::endl;
        }
    }

    return 0;
}