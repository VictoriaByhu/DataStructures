#include <iostream>
using namespace std;

struct Car{
	string name;
	int yearOfissue;
	int price;
	Car* next;
};

void ShowRelevantToConditions(Car*& head) {
	Car* current = head;
	while (current != NULL) {
		if (current->price < 5000 && (2025 - current->yearOfissue) > 10) {
			cout << current->name << endl;
			cout << current->yearOfissue << endl;
			cout << current->price << endl;
			cout << "----------------" << endl;
		}
		current = current->next;
	}

}

void FreeMemory(Car*& head) {
	
	while (head != NULL) {
		Car* current = head;
		head = head->next;
		delete current;
	}
}

int main() {
	Car* head = NULL;
	int n = 4;
	Car* car1 = new Car{ "Toyota Corola", 2006, 5000 };
	Car* car2 = new Car{ "Opel Corsa", 2009, 4500 };
	Car* car3 = new Car{ "Mersedes GL",  2012, 8500 };
	Car* car4 = new Car{ "Nissan XTrail", 2010, 10000, NULL };

	head = car1;
	car1->next = car2;
	car2->next = car3;
	car3->next = car4;

	ShowRelevantToConditions(head);
	FreeMemory(head);

	return 0;
}