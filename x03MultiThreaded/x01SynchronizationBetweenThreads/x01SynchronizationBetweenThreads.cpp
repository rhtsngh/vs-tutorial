// x01SynchronizationBetweenThreads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Header.h"
#if ENABLE_X01
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <process.h>

volatile int counter = 0;//"volatile" to prevent the compiler from optimizing the code. Reference Info: https://en.wikipedia.org/wiki/Volatile_(computer_programming)

int isPrime(int n)
{
    for (int i = 2; i < (int)(sqrt((float)n) + 1); i++) {
        if (n % i == 0) return 0;
    }

    return 1;
}

unsigned int __stdcall mythread(void*)//Q: What is __stdcall
{
    while (counter < 25) {
        int number = counter++;
        bool check = isPrime(number);
        printf("Thread %d value = %d is prime = %s\n",
            GetCurrentThreadId(), number, check ? "Yes":"No");
    }

    return 0;
}

int main()
{
    std::cout << "Hello! This is x01SynchronizationBetweenThreads\n";

    HANDLE myhandleA, myhandleB;
    myhandleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
    myhandleB = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
    
    WaitForSingleObject(myhandleA, INFINITE);
    WaitForSingleObject(myhandleB, INFINITE);

    CloseHandle(myhandleA);
    CloseHandle(myhandleB);

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
