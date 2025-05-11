#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

class Auto
{
private:
	string model;
	int year;
public:
	Auto(string n = "XTrail", int m = 2007) : model(n), year(m) {}

	void print() const
	{
		cout << "Nissan model: " << model << ", Year: " << year << endl;
	}


	bool operator<(const Auto& other) const {
		return year < other.year;
	}
};

int main()
{
	priority_queue<Auto> a;

	a.push(Auto("Leaf", rand() % 26 + 2000));
	a.push(Auto("Juke", rand() % 26 + 2000));
	a.push(Auto("Patrol", rand() % 26 + 2000));
	a.push(Auto("Frontier", rand() % 26 + 2000));

	cout << "Queue:" << endl;

	priority_queue<Auto> temp = a;
	while (!temp.empty())
	{
		temp.top().print();
		temp.pop();
	}



	return 0;
}