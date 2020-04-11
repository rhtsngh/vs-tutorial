#pragma once
#include "SimpleDLL.h"

class APIENTRY Operations
{
public:
	int m_a, m_b;
	float m_result;
	Operations(int a, int b);

	void add();
	void subtract();
	void multiply();
	void div();
};

