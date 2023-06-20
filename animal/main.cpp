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

	//virus covid1 = covid; covid1.dna[0] = '6';
	//std::cout << covid1.dna << std::endl << covid.dna;
	//std::cout << covid.amount <<std::endl<< monke.metabolism_rate << std::endl<<monke.cellular_complexity;
	//std::cout << covid1.amount << std::endl<< covid.amount<<std::endl;
	//std::cout << std::endl;

	animal** a = new animal * [9];
	animal* a1 = new animal();	a[0] = a1;
	animal* a2 = new virus();	a[1] = a2;
	animal* a3 = new vertebrates();	a[2] = a3;
	animal* a4 = new fish();	a[3] = a4;
	animal* a5 = new mammal();	a[4] = a5;
	animal* a6 = new virus();	a[5] = a6;
	animal* a7 = new cat();	a[6] = a7;
	animal* a8 = new dog();	a[7] = a8;
	animal* a9 = new cow();	a[8] = a9;
	for (int i = 0; i < 9; i++)
	{
		a[i]->sound();
		delete a[i];
	}
	delete[] a;
	



	std::cin >> l;
	return 0;
}