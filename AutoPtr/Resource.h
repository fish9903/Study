#pragma once

#include<iostream>

class Resource
{
public:
	int* m_data = nullptr;
	unsigned int m_length = 0;

public:
	Resource()
	{
		std::cout << "Resource default constructor" << std::endl;
	}

	Resource(unsigned int length_in)
	{
		std::cout << "Resource length constructor" << std::endl;

		this->m_data = new int[length_in];
		this->m_length = length_in;
	}

	Resource(const Resource& res)
	{
		std::cout << "Resource copy constructor" << std::endl;

		Resource(res.m_length);

		for (unsigned int i = 0; i < m_length; i++)
			m_data[i] = res.m_data[i];
	}

	~Resource()
	{
		std::cout << "Resource destructor" << std::endl;

		if (m_data != nullptr) delete[] m_data;
	}

	Resource& operator = (Resource& res)
	{
		std::cout << "Resource copy assignment" << std::endl;

		if (&res == this) return *this;
		if (this->m_data != nullptr) delete [] m_data;

		m_length = res.m_length;
		m_data = new int[m_length];

		for (unsigned int i = 0; i < m_length; i++)
			m_data[i] = res.m_data[i];

		return *this;
	}

	friend std::ostream& operator << (std::ostream out, const Resource R)
	{
		out << "Resource << operator" << std::endl;

		return out;
	}

	void print()
	{
		for (unsigned int i = 0; i < m_length; i++)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}

	void setAll(const int n)
	{
		for (unsigned int i = 0; i < m_length; i++)
			m_data[i] = n;
	}

};