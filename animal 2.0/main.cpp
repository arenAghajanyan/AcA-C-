#include <iostream>
#include <string>

class animal
{
public:
	animal(int const dn_size)
	{
		this->dn_size = dn_size;
		dna = new char[dn_size];
		for (int i = 0; i < 50; i++) dna[i] = dn_acyds[rand() % 4];
	}

	animal(int const dn_size, std::string const dna)
	{
		this->dn_size = dn_size;
		this->dna = new char[dn_size];
		for (int i = 0; i < dn_size; i++) this->dna[i] = dna[i];
	}

	virtual ~animal()
	{
		delete[] dna;
		dna = nullptr;
	}
	virtual void display()
	{
		for (int i = 0; i < dn_size; i++) std::cout << dna[i];
		std::cout << std::endl;
	}
	virtual void sound() = 0;

private:
	animal()
	{}
	char* dna;
	int dn_size;
	char const dn_acyds[4]{ 'a', 't', 'g', 'c' };
};

class mammal :public animal
{
public:

	mammal(int const dn_size, bool herb) :animal(dn_size)
	{
		herbivore = herb;
	}

	mammal(int const dn_size, std::string const dna, bool herb) :animal(dn_size, dna)
	{
		herbivore = herb;
	}
	
	mammal(int const dn_size, std::string const dna) :animal(dn_size, dna)
	{
		herbivore = true;
	}
	void sound() override
	{
		std::cout << "mammal reacts" << std::endl;
	}
	~mammal() override
	{
	}

private:
	bool herbivore;
	mammal();
};

class lion : public mammal
{
public:
	lion(int const dn_size) : mammal(dn_size, false)
	{
		
	}
	lion(int const dn_size, std::string const dna) : mammal(dn_size, dna, false)
	{
	
	}
	
	~lion() override
	{

	}
	void sound() override
	{
		std::cout << "lion roars" << std::endl;
	}
private:
	lion();
};


int main()
{
	lion a(8);
	a.display();
	a.sound();
	return 0;
}