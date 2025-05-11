#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void PushBack(Node*& head, int value) {
    if (head == NULL) {
        head = new Node{ value, NULL };
    }
    else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new Node{ value, NULL };
    }
}

void Show(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
   
}

bool Exists(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

void ShowRepeatedValue(Node* head) {
    Node* current = head;
    while (current != NULL) {
        if (Exists(current->next, current->data)) {
            cout << current->data << " ";
        }
        current = current->next;
    }
    cout << endl;
}

void RemoveEven(Node*& head) {
    while (head != NULL && head->data % 2 == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data % 2 == 0) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

void FreeMemory(Node*& head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    srand(time(0));
    Node* head = NULL;

    for (int i = 0; i < 10; i++) {
        PushBack(head, rand() % 21);
    }

    Show(head);
    cout << "Repetative values: ";
    ShowRepeatedValue(head);

    RemoveEven(head);
    Show(head);

    FreeMemory(head);
    return 0;
}
