#include <iostream>
using namespace std;	

struct student {
	string name;
	int group;
	float ses[5];
	float averageMark(float ses[5]) {
		float sum = 0;
		for (int i = 0; i < 5; i++) {
			sum += ses[i];
		}
		float avg = sum / 5;

		return avg;
	}

};

bool startsWithVowel(string name) {
	char firstLetter = name[0];

	return firstLetter == 'A' || firstLetter == 'E' || firstLetter == 'I' || firstLetter == 'O' || firstLetter == 'U' || firstLetter == 'Y';
}

void bubbleSort(student s[5]) {
	for (int i = 0; i < 5 - 1; i++) {
		for (int j = 4; j >= i; j--) {
			if (s[j].averageMark(s[j].ses) < s[j - 1].averageMark(s[j - 1].ses)) {
				student temp = s[j];
				s[j] = s[j - 1];
				s[j - 1] = temp;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		cout << s[i].name << " " << s[i].group << " ";
		for (int j = 0; j < 5; j++) {
			cout << s[i].ses[j] << " ";
		}
		cout << endl;
	}
}

void elementRemoval(student s[5], student* p ) {
	int min = s[0].averageMark(s[0].ses);
	int index = 0;

	for (int i = 0; i < 5; i++) {
		if (s[i].averageMark(s[i].ses) < min) {
			min = s[i].averageMark(s[i].ses);
			index = i;
		}
	}

	index++;

	if (index >= 5) {
		cout << "There is no element after minimum";
		return;
	}
	
	int j = 0;
	for (int i = 0; i < 5; i++) {
		if (i != index) {
			p[j] = s[i];
			j++;
		}
		
	}

	for (int i = 0; i < 4; i++) {
		cout << p[i].name << " " << p[i].group << " ";
		for (int j = 0; j < 5; j++) {
			cout << p[i].ses[j] << " ";
		}
		cout << endl;
	}

}

int main() {
	student s[5] = {
		{"Oleynyk O.A.", 156, {5.0, 1.5, 2.2, 4.5, 3.5}},
		{"Koval'chuk A.V.", 220, {4.5, 2.0, 5.0, 5.0, 5.0}},
		{"Malysh M.D.", 114, {1.0, 2.0, 3.0, 3.2, 1.5}},
		{"Gryn'ko V.U.", 132, {5.0, 3.0, 4.0, 5.0, 1.5}},
		{"Bozhenko P.A", 303, {1.5, 2.5, 3.0, 4.5, 1.5}}
	};

	student* p = new student[4];

	int lowerThanFour = 0;
	cout << "Students with average mark higher than 4.0: " << endl;	
	for (int i = 0; i < 5; i++) {
		if (s[i].averageMark(s[i].ses) > 4) {
			cout << s[i].name << " " << s[i].group << endl;
		}
		else {
			lowerThanFour++;
		}

	}
	if (lowerThanFour == 5) {
		cout << "There are no students with average mark higher than 4.0" << endl;
	}
	cout << endl;

	cout << "Data of students whose names start with a vowel: " << endl;
	for (int i = 0; i < 5; i++) {
		if (startsWithVowel(s[i].name)) {
			cout << s[i].name << " " << s[i].group << " ";
			for (int j = 0; j < 5; j++) {
				cout << s[i].ses[j] << " ";
			}
			cout << endl;
		}
	}
	cout << endl;

	cout << "Sorted list of students: " << endl;
	bubbleSort(s);
	cout << endl;

	cout << "Updated list of students: " << endl;
	elementRemoval(s, p);


	return 0;
}