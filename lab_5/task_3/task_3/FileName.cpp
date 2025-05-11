#include <iostream>
using namespace std;

struct Student {
	string name;
	float height;
	float weight;
	Student* next;
};

void PushBack(Student*& head, string name, float weight, float height) {
    Student* newStudent = new Student;
    newStudent->name = name;
    newStudent->height = height;
    newStudent->weight = weight;
    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    }
    else {
        Student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
    }
	
}

void Show(Student* head) {
	Student* current = head;
	while (current != NULL) {
		cout <<"Name: "<< current->name << endl;
		cout << "Height: " << current->height << endl;
		cout << "Weight: " << current->weight << endl;
		cout << "----------------" << endl;
		current = current->next;
	}
	
}

void HigherThan(Student* head) {
	Student* current = head;
	while (current != NULL) {
		
		char firstLetter = tolower(current->name[0]);
		if (current->height > 170 && firstLetter == 'o') {
			cout << "Students higher than 170 cm and whose names start with 'O': " << endl;
			cout << "Name: " << current->name << endl;
			cout << "Height: " << current->height << endl;
			cout << "Weight: " << current->weight << endl;
			cout << "----------------" << endl;
		}
		current = current->next;
	}
}

float MinWeight(Student* head) {
	Student* current = head;
	float weight = current->weight;

	while (current != NULL) {
		if (current->weight < weight) {
			weight = current->weight;
		}
		current = current->next;
	}

	return weight;
}

void Remove(Student*& head) {
	Student* previous = NULL;
	Student* current = head;



	while (current != NULL) {
		if (current->weight == MinWeight(head)) {
			previous->next = current->next;
				delete current;
				return;		
		}
		previous = current;
		current = current->next;
	}

}

void freeMemory(Student*& head) {
	while (head != NULL) {
		Student* current = head;
		head = head->next;
		delete current;
	}
}



int main() {
	Student* head = NULL;
    int n = 4;
	Student* student1 = new Student{ "Ivan", 180, 80};
	Student* student2 = new Student{ "Petro", 160, 60};
	Student* student3 = new Student{ "Oleg",  175, 70 };
	Student* student4 = new Student{ "Olena", 150, 50 };

	head = student1;
	student1->next = student2;
	student2->next = student3;
	student3->next = student4;
	student4->next = NULL;

	/*for (int i = 0; i < n; i++) {
		string name;
		float height;
		float weight;

		cout << "Enter student " << i + 1 << " name: ";
		cin >> name;
		cout << "Enter student " << i + 1 << " height: ";
		cin >> height;
		cout << "Enter student " << i + 1 << " weight: ";
		cin >> weight;
		PushBack(head, name, weight, height);
	}*/

	Show(head);
	HigherThan(head);
	Remove(head);
	Show(head);
	freeMemory(head);

	return 0;
}