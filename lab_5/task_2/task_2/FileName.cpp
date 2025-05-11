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

void Show(Node* head) {
	Node* current = head;
	while (current != NULL) {
		cout << current->data << " -> ";
		current = current->next;
	}
	cout << "NULL\n";
}

int FindMaxValue(Node* head) {
	Node* current = head;
	int max = current->data;
	while (current != NULL) {
		if (current->data > max) {
			max = current->data;
			
		}
		current = current->next;
	}
	return max;
}

int FindMinValue(Node* head) {
	Node* current = head;
	int min = current->data;
	while (current != NULL) {
		if (current->data < min) {
			min = current->data;
			
		}
		current = current->next;
	}
	return min;
}

int FindDifferentValue(Node* head) {
	Node* current = head;
	int value = 0;
	while (current != NULL) {
		if (current->data != FindMaxValue(head) && current->data != FindMinValue(head)) {
			value = current->data;
		}
		current = current->next;
	}
	return value;
}

void Remove(Node*& head) {
	Node* previous = NULL;
	Node* current = head;
	
	
	
	while (current != NULL) {
		if (current->data == FindDifferentValue(head)) {
			if (previous == NULL) {
				head = current->next;
				delete current;
				return;
			}
			else {
				previous->next = current->next;
				delete current;
				return;
			}
			
		}
		previous = current;
		current = current->next;
	}
	
}

int main() {
	Node* head = new Node{ 3, NULL };
	
	if (head->data > 0) {
		PushBack(head, 5);
		PushBack(head, 9);
	}
	else if (head->data < 0) {
		PushFront(head, 5);
		PushFront(head, 9);
	}
	
	Show(head);

	FindMaxValue(head);
	FindMinValue(head);
	Remove(head);

	Show(head);
	

	return 0;
}