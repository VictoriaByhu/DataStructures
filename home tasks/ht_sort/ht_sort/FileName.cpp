#include <iostream>
using namespace std;

const int SIZE = 5;

class Notebook
{
private:
	string brand;
	int memoryCapacity;
	double price;
public:
	

	Notebook(int m = 8, int p = 30000, string b = "Lenovo") : brand(b), memoryCapacity(m), price(p) {}
};

void sort(Notebook* laptop[])
{

}

int main()
{
	Notebook laptop[SIZE] =
	{
		Notebook(8, 25000),
		Notebook(16, 33000),
		Notebook(8, 20000),
		Notebook(10, 25000),
		Notebook(20, 50000)
	};

	

	return 0;
}