#include <iostream>
#include <string>
#include "animal.h"

animal::animal() 
{
	cellular_complexity = 0;
	metabolism_rate = 2;
}
animal::animal(bool complexity, int metabolism) 
{
		cellular_complexity = complexity;
		metabolism_rate = metabolism;
}
bool animal::check_alive()
{
	if (metabolism_rate <= 0) 
	{
		std::cout << "The subject is dead" << std::endl;
		return false;
	}
		std::cout << "The subject is alive" << std::endl;
		return true;
}
void animal::change_metabolism(double n)
{
		metabolism_rate *= n;
		if (metabolism_rate <= 0) std::cout << "the has died" << std::endl;
		else std::cout << "the subject is ok" << std::endl;
}
void animal::die()
{
		if (check_alive()) change_metabolism(-1);
}
void animal::evolve() 
{
	cellular_complexity += 1;
	metabolism_rate *= 2;
}

//virus section

virus::virus()
{
	amount = 1;
	strength = 20;
}
virus::virus(int str)
{
	strength = str;
	amount = str - str % 10;
}
void virus::find(animal prey)
{
	amount *= prey.cellular_complexity;
	prey.change_metabolism(0.5);
}