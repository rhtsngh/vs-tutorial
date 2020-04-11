#include "pch.h"
#include "Operations.h"

Operations::Operations(int a, int b)
{
	m_a = a;
	m_b = b;
	m_result = m_a + m_b;
}

void Operations::add()
{
	m_result = m_a + m_b;
}
void Operations::subtract()
{
	m_result = m_a - m_b;
}
void Operations::multiply()
{
	m_result = m_a * m_b;
}
void Operations::div()
{
	m_result = (float)m_a / m_b;
}
