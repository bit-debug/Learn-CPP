// Learn-CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	int dummy = 0;
	auto f1 = [=]() { dummy = 1; };
	auto f2 = [&]() { dummy = 2; };

	std::cout << "before f1" << std::endl;
	std::cout << "  dummy = " << dummy << std::endl;

	f1();
	std::cout << "after f1" << std::endl;
	std::cout << "  dummy = " << dummy << std::endl;

	std::cout << "before f2" << std::endl;
	std::cout << "  dummy = " << dummy << std::endl;

	f2();
	std::cout << "after f2" << std::endl;
	std::cout << "  dummy = " << dummy << std::endl;


}

