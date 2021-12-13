#include <iostream>
#include "./Laba1/Laba1.h"
#include "./Laba2/Laba2.h"
#include "./Laba3/Laba3.h"
#include "./Laba4/Laba4.h"

using namespace std;

int main(int argc, char** argv)
{
	int labNumber = 0;

	while (true)
	{
		std::cout << "Please enter the lab number!\n";
		cin >> labNumber;
		switch (labNumber)
		{
		case 1:
			return Laba1::main(argc, argv);
		case 2:
			return Laba2::main(argc, argv);
		case 3:
			return Laba3::main(argc, argv);
		case 4:
			return Laba4::main(argc, argv);
		default:
			cout << "There is no such number!\n";
			break;
		}
	}
}