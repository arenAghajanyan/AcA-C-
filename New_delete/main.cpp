#include <iostream>
void* operator new(size_t size)
{
	void* p = malloc(size);
	std::cout << "overloaded new";
	if (p != nullptr) return p;
	else {
		throw std::runtime_error("bad allocation");
	}
}

void operator delete(void* p)
{
	std::cout << "overloaded delete";
	if (p != nullptr) free(p);
}
int main()
{
	int* a = new int(10);

}