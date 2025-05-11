#include <iostream>
using namespace std;	
struct students {
	string surname;
	string name;
	float scholarship;
	float hoursSkipped;
};
students x[4] = {
	{"Petrenko", "Ivan", 1500, 0},
	{"Kovalenko", "Maria", 2000, 1},
	{"Sydorenko", "Oleg", 1900, 3},
	{"Verbyc'ka", "Nataliia", 0, 1.5}
};
int main() {
	
	int n = 4;

	for (int i = 0; i < n; i++) {
		if (x[i].scholarship > 0 && x[i].hoursSkipped < 2) {
			cout << "Surname: " << x[i].surname << endl;
			cout << "Name: " << x[i].name << endl;
			cout << "Scholarship: " << x[i].scholarship << endl;
			cout << "Hours skipped: " << x[i].hoursSkipped << endl;
			cout << endl;
		}
	}

	float totalHoursSkipped = 0;

	for (int i = 0; i < n; i++) {
		totalHoursSkipped += x[i].hoursSkipped;
	}

	cout << "Total hours skipped: " << totalHoursSkipped << endl;

	return 0;
}