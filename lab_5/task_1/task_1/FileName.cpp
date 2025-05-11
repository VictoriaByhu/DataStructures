#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void PushBack(Node*& head, int value) {
	if (head == NULL) { 
		head = new Node{ value, NULL };
	}
	else 
	{
		Node* current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new Node{ value, NULL };
	}
}

void PushFront(Node*& head, int value) {
	if (head == NULL) {
		head = new Node{ value, NULL };
	}
	else {
		Node* newHead = new Node{ value, head };
		head = newHead;
	}
}

void insertMiddle(Node*& head, int value) {
	Node* current = head;
	int count = 0;

	while (current != NULL && count < 1) {
		current = current->next;
		count++;
	}

	if (current != NULL) {
		Node* newNode = new Node{ value, current->next };
		current->next = newNode;
	}
}

void Show(Node* head) {
	Node* current = head;
	while (current != NULL) {
		cout << current->data << " -> ";
		current = current->next;
	}
	cout << "NULL\n";
}

void FindAverageValue(Node* head) {
	int sum = 0, count = 0;
	while (head != NULL) {
		sum += head->data;
		count++;
		head = head->next;
	}

	float average = sum / count;
	cout << "Average value: " << average;
}

void FreeMemory(Node*& head) {
	while (head != NULL) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

int main() {

	Node* head = NULL;
	
	PushBack(head, 20);
	for (int i = 0; i < 2; i++)
	{
		PushFront(head, i);
	}
	insertMiddle(head, 15);
	Show(head);
	FindAverageValue(head);
	FreeMemory(head);

	return 0;
}
