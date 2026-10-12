#pragma once
#ifndef CANCELLATION_STACK_H
#define CANCELLATION_STACK_H

#include "Reservation.h"

class CancellationStack
{
private:
    struct Node
    {
        Reservation reservation;
        Node* next;

        Node(const Reservation& res)
            : reservation(res), next(nullptr)
        {
        }
    };

    Node* top;

public:
    CancellationStack();
    ~CancellationStack();

    void push(Reservation reservation);
    Reservation pop();
    Reservation getTop();
    bool isEmpty();
    void displayCancellationHistory();
};

#endif
