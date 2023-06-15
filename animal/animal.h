#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
class animal
{
public:
	int cellular_complexity;
	int metabolism_rate;
	animal();
	animal(int complexity, int metabolism);
	bool check_alive();
	void set_metabolizm(int n);
	void change_metabolism(int n);
	void die();
	void evolve();
};

class vertebrates : public animal
{
public:
	int nerv_system;
	int immunity;
	bool oxygen_dependant;
	bool land_based;
	vertebrates();
	vertebrates(int nerves, int immune_stat, bool place);
	void breath(int atmosphere);
	void flee();
	void rest(int time);
};
class mammal : public vertebrates
{
public:
	mammal();
	mammal(bool h, bool c);
	bool herbivore;
	bool carnivor;
	int brain;
	void mate();
	void adapt();
};

class virus : public animal
{
public:
	int amount;
	int strength;
	virus();
	virus(int str);
	void find(animal prey);
	void find(vertebrates prey);
	void find(mammal prey);
};

#endif