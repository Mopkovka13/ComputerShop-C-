#include "Extra.h"
#include <iostream>
#include <string>

float isFloat()
{
	float a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Print number: ";
	}
	return a;
}

int isInt()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Print number: ";
	}
	return a;
}

bool isBool()
{
	std::string a;
	std::cin >> a;
	for (int i = 0;i < 30;i++)
	{
		if (a == "true")
			return true;
		if (a == "false")
			return false;
		std::cout << "Print (true/false) : ";
		std::cin >> a;
		if (i == 29)
			std::cout << "\n\t;(\n";
	}
}
