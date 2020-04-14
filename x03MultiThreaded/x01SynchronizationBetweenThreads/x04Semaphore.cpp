// x04Semaphore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"
#if ENABLE_X04
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <process.h>

HANDLE semaphore;
int count = 0;

void addCount(int value)
{
    WaitForSingleObject(semaphore, INFINITE);
    count += value;
    ReleaseSemaphore(semaphore, 1, 0);
}

unsigned int __stdcall mythread(void*)//Q: What is __stdcall
{
    for (int i = 0; i < 50; i++) {
        addCount(2);
        printf("Thread %d value = %d\n",
            GetCurrentThreadId(), count);
    }

    return 0;
}

int main()
{
    std::cout << "Hello! This is x02CriticalSections\n";

    HANDLE myhandleA, myhandleB;
    semaphore = CreateSemaphore(0, 1, 1, 0);
    myhandleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
    myhandleB = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);

    WaitForSingleObject(myhandleA, INFINITE);
    WaitForSingleObject(myhandleB, INFINITE);

    CloseHandle(myhandleA);
    CloseHandle(myhandleB);

    printf("count = %d\n", count);

    CloseHandle(semaphore);

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
