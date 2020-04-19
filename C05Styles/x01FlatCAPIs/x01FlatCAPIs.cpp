// x01FlatCAPIs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define CPPSTACK 1
#define FLATCSTACK 2
#define TEST 2

#if TEST == CPPSTACK
#include "CPPStack.h"
#elif TEST == FLATCSTACK
#include "FLATCStack.h"
#endif


int main()
{
    std::cout << "Hello World!\n";

#if TEST == CPPSTACK
    Stack *s = new Stack();
    s->Push(2);
    s->Push(4);//exited with code 0(OK)
    //s->Push(5);//exited with code 1(ERROR)
    std::cout << s->Pop() << std::endl;
    std::cout << s->Pop() << std::endl;//exited with code 0(OK)
    //std::cout << s->Pop() << std::endl;//exited with code 1(ERROR)
    delete s;
#elif TEST == FLATCSTACK
    StackPtr s = StackCreate();
    StackPush(s, 3);
    StackPush(s, 7);
    StackPush(s, 2);//no active
    std::cout << StackPop(s) << std::endl;
    std::cout << StackPop(s) << std::endl;
    std::cout << StackPop(s) << std::endl;//no active
#endif

#if TEST == VIRTUAL
    class base {
    public:
        void fun_1() { std::cout << "base-1\n"; }
        virtual void fun_2() { std::cout << "base-2\n"; }
        virtual void fun_3() { std::cout << "base-3\n"; }
        virtual void fun_4() { std::cout << "base-4\n"; }
    };

    class derived : public base {
    public:
        void fun_1() { std::cout << "derived-1\n"; }
        void fun_2() { std::cout << "derived-2\n"; }
        void fun_4(int x) { std::cout << "derived-4\n"; }
    };

    base* p;
    derived obj1;
    p = &obj1;

    // Early binding because fun1() is non-virtual 
    // in base 
    p->fun_1();
    // Late binding (RTP) 
    p->fun_2();
    // Late binding (RTP) 
    p->fun_3();
    // Late binding (RTP) 
    p->fun_4();

    obj1.fun_1();
    obj1.fun_2();
    obj1.fun_3();
    obj1.fun_4(5);
#endif
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
