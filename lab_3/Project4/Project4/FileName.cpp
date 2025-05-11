#include <iostream>
using namespace std;
struct workers {
	string surnameAndInitials;
	string position;
	int yearOfEmployment;
	int salary;
};

int experience(workers worker) {
	return 2025 - worker.yearOfEmployment;
}
float salary(workers worker) {
	return worker.salary * (1 - 0.33);
}
int main() {
	workers worker[5] = {
		{"Ivanov I.V.", "Director", 2000, 4000},
		{"Petrova N.P.", "Manager", 2005, 3000},
		{"Sidorov S.R.", "Engineer", 2010, 2500},
		{"Vasilev O.V.", "Programmer", 2015, 2000},
		{"Bondar R.O.", "Cleaner", 2020, 800}
	};

	for (int i = 0; i < 5; i++) {
		cout << worker[i].surnameAndInitials << " experience: " << experience(worker[i]) << " years" << endl;
		cout << worker[i].surnameAndInitials << " salary: " << salary(worker[i]) << " USD" << endl;
		cout << endl;
	}




	return 0;
}