#include<iostream>
#include<memory>

#include"AutoPtr.h"
#include"Resource.h"

using namespace std;

AutoPtr<Resource> generateResource()
{
	AutoPtr<Resource> res(new Resource(10000000));

	return res;
}

template<class T>
void MySwap(T& a, T& b)
{
	/*T tmp = a;
	a = b;
	b = tmp;*/

	T tmp{ std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	{
		auto res1 = std::make_unique<Resource>(5);

		unique_ptr<Resource> res2;

		res1->setAll(1);
		res1->print();

		res2 = std::move(res1);

		if (res1 != nullptr)
		{
			std::cout << "This is res1->print()" << std::endl;
			res1->print();
		}

		if (res2 != nullptr) 
		{
			std::cout << "This is res2->print()" << std::endl;
			res2->print(); 
		}

	}

	return 0;
}