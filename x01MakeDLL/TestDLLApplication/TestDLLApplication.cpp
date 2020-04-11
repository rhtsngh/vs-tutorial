// TestDLLApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Variables.h"
#include "Functions.h"
#include "Operations.h"

int main()
{
    std::cout << "Hello! This is Test-DLL Application\n";

    std::cout << "1. Test Library of Variables: " << PI << std::endl;

    std::cout << "2. Test Library of Functions: " << Add(7, 2) << std::endl;
    SayHello();

    std::cout << "3. Test Library of Class: " << std::endl;
    Operations op(8, 4);
    std::cout << " - Add: " << op.m_result << std::endl;
    op.subtract();
    std::cout << " - Subtract: " << op.m_result << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
