// x01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <iostream>

#include <libs/gl3w/GL/gl3w.h>
#include <libs/glfw/include/GLFW/glfw3.h>

#pragma comment(lib, "legacy_stdio_definitions")

static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main()
{
    std::cout << "Hello World!\n";

	//// Setup window
	//glfwSetErrorCallback(glfw_error_callback);
	//if (!glfwInit())
	//	return 1;

	//// GL 3.0 + GLSL 130
	//const char* glsl_version = "#version 130";
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

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
