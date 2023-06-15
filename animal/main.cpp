#include <iostream>
#include <string>
#include "animal.h"


int main()
{
	int l;
	animal cell1(1,12);
	virus covid(205);
	vertebrates fish1(20, 12, 0);
	mammal monke(1, 1);

	cell1.check_alive();
	covid.find(cell1);
	cell1.change_metabolism(-2);
	cell1.check_alive();
	fish1.breath(0);
	covid.find(fish1);
	covid.find(monke);
	monke.check_alive();
	//std::cout << covid.amount <<std::endl<< monke.metabolism_rate << std::endl<<monke.cellular_complexity;
	std::cin >> l;
	return 0;
}