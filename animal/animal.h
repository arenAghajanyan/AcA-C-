#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>



class animal
{
public:
	char static dn_acyds[4];
	char* dna;

	int cellular_complexity;
	int metabolism_rate;
	animal();
	animal(int complexity, int metabolism);
	animal(const animal& an1);
	bool check_alive();
	void set_metabolizm(int n);
	void change_metabolism(int n);
	void die();
	void evolve();
	virtual void sound();
	~animal();
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
	virtual void sound();
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
	virtual void sound();
};



class dog : public mammal
{
public:
	dog();
	virtual void sound();
};


class cat : public mammal
{
public:
	cat();
	virtual void sound();
};

class cow : public mammal
{
public:
	cow();
	virtual void sound();
};



class fish : public vertebrates
{
public:
	bool static swims;
	fish();
	virtual void sound();
};


class dolphin :public mammal, fish
{
public:
	dolphin();
	virtual void sound();
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
	virtual void sound();
};

#endif