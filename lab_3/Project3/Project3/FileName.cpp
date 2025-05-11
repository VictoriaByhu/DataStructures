#include <iostream>
using namespace std;
struct abiturient {
	string surname;
	string name;
	string adress;
	int marks[3];
};

float averageScore(int marks[3]) {
	float sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += marks[i];
	}
	return sum / 3;
}
int main() {
	abiturient abits[3] = {
		{"Melnyk", "Oleksandr", "vul. Lesi Ukrainky, 12, m. Lviv, 79000", {156, 175, 200}},
		{"Shevchenko", "Viktoriia", "vul. Soborna, 103, m. Dnipro, 49000", {134, 120, 109}},
		{"Petrenko", "Anastasiia", "vul. Shevchenka, 23, m. Kyiv, 02000", {168, 159, 143}}
	};

	float passingScore = 150;

	for (int i = 0; i < 3; i++) {
		if (averageScore(abits[i].marks) > passingScore) {
			cout << abits[i].surname << " " << abits[i].name << " " << abits[i].adress << endl;
		}
	}



	return 0;
}