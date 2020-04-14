// x05Events.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Explanation:
//  - mythreadA runs first to wait for myEvent occuring
//  - mythreadB runs after to trigger myEvent
//  - that leads to: even mythreadA is active firstly, the job A is operated after job B.

#include "Header.h"
#if ENABLE_X05
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <process.h>

HANDLE myEvent;

/* The first thread executes the routine myThreadA() and waits on the event. */
unsigned int __stdcall mythreadA(void* param)//Q: What is __stdcall
{
    WaitForSingleObject(myEvent, INFINITE);
    printf("Event is acknowledged\n");
    printf("Thread A finished\n");

    return 0;
}

unsigned int __stdcall mythreadB(void* param)//Q: What is __stdcall
{
    printf("Thread B finished\n");
    printf("Now set the Event\n");
    /* A call to SetEvent() places the event into the signaled state.
    This allows threads waiting on the event
    using WaitForSingleObject() to be released. */
    SetEvent(myEvent);

    return 0;
}

int main()
{
    std::cout << "Hello! This is x05Events\n";

    HANDLE myhandleA, myhandleB;
    myEvent = CreateEvent(0, 0, 0, 0);
    myhandleA = (HANDLE)_beginthreadex(0, 0, &mythreadA, (void*)0, 0, 0);
    myhandleB = (HANDLE)_beginthreadex(0, 0, &mythreadB, (void*)0, 0, 0);

    WaitForSingleObject(myhandleA, INFINITE);
    WaitForSingleObject(myhandleB, INFINITE);

    CloseHandle(myhandleA);
    CloseHandle(myhandleB);

    CloseHandle(myEvent);

    std::cout << "Byebye!\n";

    return 0;
}
#endif
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
