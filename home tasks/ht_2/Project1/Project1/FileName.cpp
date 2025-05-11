#include <iostream>
#include <string>
using namespace std;

struct employee
{
	string surname, name, jobPosition;
	float salary, hoursWorked;
};

int main() {
	employee x[4] = {
		{"Petrenko", "Ivan", "Director", 2000, 200},
		{"Kovalenko", "Maria", "HR", 1500, 160},
		{"Sydorenko", "Oleg", "Manager", 1000, 100},
		{"Verbyc'ka", "Nataliia", "Designer", 2000, 200},
	};
	int n = 4;


	

	cout << "----------------------------------------------------" << endl;
	int sum = 0;
	int count = 0;
	
	for (int i = 0; i < n; i++) {
		count++;
		sum += x[i].salary;
	}
	float average = sum / count;

	for (int i = 0; i < n; i++) {
		if (x[i].salary > average && x[i].hoursWorked >= 160) {
			cout << x[i].surname << endl<<
				x[i].name << endl<<
				x[i].jobPosition <<endl<<
				x[i].salary <<endl<<
				x[i].hoursWorked << endl;
			cout << endl;
		}

	}
	cout << "----------------------------------------------------" << endl;

	string employeePosition;
	cout << "Enter job position to find employee: ";
	getline(cin, employeePosition);

	for (int i = 0; i < n; i++) {
		if (x[i].jobPosition == employeePosition) {
			cout << x[i].surname << endl <<
				x[i].name << endl <<
				x[i].jobPosition << endl <<
				x[i].salary << endl <<
				x[i].hoursWorked << endl;
		}
	}


	return 0;
}