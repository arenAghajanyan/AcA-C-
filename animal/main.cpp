#include <iostream>
#include <string>
#include "animal.h"


int main()
{
	int l;
	animal cell(1,12);
	cell.check_alive();

	virus covid(205);
	covid.find(cell);
	cell.change_metabolism(-2);
	cell.check_alive();
	std::cin >> l;
	return 0;
}