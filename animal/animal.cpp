#include <iostream>
#include <string>
#include "animal.h"

char animal::dn_acyds[4]{ 'a', 't', 'g', 'c'};
animal::animal() 
{
	dna = new char[50];
	for (int i = 0; i < 50; i++) dna[i] = dn_acyds[rand()%4];
	cellular_complexity = 1;
	metabolism_rate = 2;
}
animal::animal(int complexity, int metabolism) 
{
	dna = new char[50];
	for (int i = 0; i < 50; i++) dna[i] = dn_acyds[rand() % 4];
	cellular_complexity = complexity;
	metabolism_rate = metabolism;
}
animal::animal(const animal& an1)
{
	if (this != &an1)
	{
		dna = new char[50];
		for (int i = 0; i < 50; i++) dna[i] = an1.dna[i];
		cellular_complexity = an1.cellular_complexity;
		metabolism_rate = an1.metabolism_rate;
	}
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
void animal::sound()
{
	std::cout << "the animal reacts" << std::endl;
}
animal::~animal()
{
	delete(dna);
	dna = nullptr;
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
void vertebrates::sound()
{
	std::cout << "brrrs" << std::endl;
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
void mammal::sound()
{
	if (carnivor == true) std::cout << "Roars" << std::endl;
	else  std::cout << "groans" << std::endl;
}


//dog section


dog::dog()
{
	carnivor = 1;
	herbivore = 1;
}
void dog::sound()
{
	std::cout << "barks" << std::endl;
}


//cat section


cat::cat()
{
	carnivor = 1;
	herbivore = 0;
}
void cat::sound()
{
	std::cout << "Meow" << std::endl;
}


//cow section

cow::cow()
{
	herbivore = 1;
	carnivor = 0;
}
void cow::sound()
{
	std::cout << "moos" << std::endl;
}



//fish section


bool fish::swims=1;
fish::fish()
{

}
void fish::sound()
{
	std::cout << "the sound is too scilent to be heard" << std::endl;
}



dolphin::dolphin()
{
	mammal::land_based = false;	
	fish::land_based = false;

}
void dolphin::sound()
{
	std::cout << "ikikikik" << std::endl;
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
void virus::sound()
{
	std::cout << "the virus can't make a sound" << std::endl;
}
