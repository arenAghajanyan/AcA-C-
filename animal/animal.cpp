#include <iostream>
#include <string>
#include "animal.h"

animal::animal() 
{
	cellular_complexity = 1;
	metabolism_rate = 2;
}
animal::animal(int complexity, int metabolism) 
{
		cellular_complexity = complexity;
		metabolism_rate = metabolism;
}
bool animal::check_alive()
{
	if (metabolism_rate <= 0 || metabolism_rate>=(100*cellular_complexity))
	{
		std::cout << "The subject is dead" << std::endl;
		return false;
	}
		std::cout << "The subject is alive" << std::endl;
		return true;
}
void animal::set_metabolizm(int n)
{
	metabolism_rate = n;
}
void animal::change_metabolism(int n)
{
		metabolism_rate += n;
		if (metabolism_rate <= 0 || metabolism_rate >= (90 * cellular_complexity)) std::cout << "the subject is in danger" << std::endl;
		else std::cout << "the subject is ok" << std::endl;}
void animal::die()
{
		if (check_alive()) change_metabolism(-100000);
		std::cout << "The subject is now dead" << std::endl;

}
void animal::evolve() 
{
	if (cellular_complexity <= 50)
	{
		cellular_complexity += 1;
		metabolism_rate += 1;
	}
	else std::cout << "must change type to evolve" << std::endl;
}

//vertebrates section

vertebrates::vertebrates()
{	
	cellular_complexity = 65;
	metabolism_rate = 15;
	nerv_system = 12;
	immunity = 10;
	land_based = false;
	oxygen_dependant = true;
}
vertebrates::vertebrates(int nerves, int immune_stat, bool place)
{
	cellular_complexity = 65;
	metabolism_rate = 15;
	nerv_system = nerves;
	immunity = immune_stat;
	land_based = place;
	oxygen_dependant = true;
}
void vertebrates::breath(int atmosphere)
{
	if (cellular_complexity > atmosphere)
	{
		std::cout << "not ennough oxygen" << std::endl;
		immunity /= 2;
		change_metabolism(-metabolism_rate/2);
	}
	else evolve();
}
void vertebrates::flee()
{
	change_metabolism(metabolism_rate);
}
void vertebrates::rest(int time)
{
	if (time <= 0)std::cout << "negative number given for time" << std::endl;
	else immunity += time;
}


//mammals section

mammal::mammal() 
{
	cellular_complexity = 100;
	herbivore = true;
	carnivor = false;
	nerv_system = nerv_system * herbivore + nerv_system * carnivor;
	brain = nerv_system * cellular_complexity;
}
mammal::mammal(bool h, bool c)
{
	cellular_complexity = 100;
	herbivore = h;
	carnivor = c;
	nerv_system = nerv_system * herbivore + nerv_system * carnivor;
	brain = nerv_system * cellular_complexity;
}
void mammal::mate()
{
	cellular_complexity+=1;
	immunity+=1;
}
void mammal::adapt()
{
	immunity += 10;
	set_metabolizm(50);
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
	prey.change_metabolism(-10);
}
void virus::find(vertebrates prey)
{
	amount *= prey.cellular_complexity - prey.immunity;
	if (strength > prey.immunity)	prey.change_metabolism(prey.immunity - strength);
}
void virus::find(mammal prey)
{
	amount *= prey.cellular_complexity - prey.immunity;
	std::cout << "virus attacked a mammal" << std::endl;
	if (strength > prey.immunity)	prey.change_metabolism(prey.immunity - strength);
	std::cout << "mammal adapts" << std::endl;
	prey.adapt();
	amount /= prey.immunity;
}
