#include <iostream>

class Array
{
public:
	int& p = ptr;
	Array(int size) : size(size)
	{
		ptr = new int[size];

	}
	void fill()
	{
		for (int i = 0; i < size; i++) {
			ptr[i] = rand()%100;
		}
	}
	Array(const Array& other) : size(other.size) 
	{
		ptr = new int[size];
		for (int i = 0; i < size; i++) {
			ptr[i] = other.ptr[i];
		}
	}
	virtual ~Array() 
	{
		delete ptr;
	}

	int get_element(int n)
	{
		if (n < size)
			return ptr[n];
		else
		{
			std::cerr << "out of range" << std::endl;
			return 0;
		}
	}

private:
	Array();
	int* ptr;
	int size;
};

int main() {
	Array a(8);
	a.fill();
	Array b = a;
	b.p[0] += 3;
	std::cout << b.get_element(0) << a.get_element(0) << std::endl;
	return 0;
}