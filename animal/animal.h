#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
class animal
{
public:
	bool cellular_complexity;
	int metabolism_rate;

	animal();
	animal(bool complexity, int metabolism);
	bool check_alive();
	void change_metabolism(double n);
	void die();
	void evolve();
};

class virus: public animal
{
public:
	int amount;
	int strength;
	virus();
	virus(int str);
	void find(animal prey);

};
class vertebrates : public animal
{
	int nerv_system;
	bool land_based;
	int immunity;
	bool oxygen_dependant;
	void breath(int atmosphere);
	void flee();
	void rest(int time);
};
class mammal : public vertebrates
{
	
};

#endif