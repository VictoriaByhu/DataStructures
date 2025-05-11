#include <iostream>
#include <iomanip>

struct NumbersQueue {
    int number;
    NumbersQueue* next;
}*front = nullptr, * rear = nullptr;

void enqueue(int number) {
    NumbersQueue* newNumber = new NumbersQueue;
    newNumber->number = number;
    newNumber->next = nullptr;
    if (rear == nullptr) {
        front = rear = newNumber;
        return;
    }
    rear->next = newNumber;
    rear = newNumber;
}

void addElenentAfterValue(int number, int value) {
    NumbersQueue* temp = front;
    while (temp != nullptr) {
        if (temp->number == value) {
            NumbersQueue* newNumber = new NumbersQueue;
            newNumber->number = number;
            newNumber->next = temp->next;
            temp->next = newNumber;
            if (newNumber->next == nullptr) rear = newNumber;
            return;
        }
        temp = temp->next;
    }
}

double averageGeometic(NumbersQueue* front) {
    NumbersQueue* temp = front;
    double product = 1.0;
    int counter = 0;
    while (temp) {
        product *= temp->number;
        counter++;
        temp = temp->next;
    }
    return pow(product, 1.0 / counter);

}

void clearQueueNums(NumbersQueue*& front) {
    NumbersQueue* temp = front;
    while (temp) {
        NumbersQueue* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    front = nullptr;
    rear = nullptr;
}


int main() {
    int num;
    std::cout << "Enter number of elements in list:\n";
    std::cin >> num;
    while (num <= 0) {
        std::cout << "List should contain at least 1 element\n";
        std::cout << "Enter number of elements in list:\n";
        std::cin >> num;
    }
    for (int i = 0; i < num; i++) {
        enqueue(rand() % 98 + 1);
    }
    std::cout << "Your queue: ";
    NumbersQueue* temp = front;
    while (temp) {
        std::cout << temp->number << (temp->next == nullptr ? " " : "->");
        temp = temp->next;
    }
    temp = front;
    while (temp) {
        if (temp->number % 2 == 0 && temp->number != 100) {
            addElenentAfterValue(100, temp->number);

        }
        temp = temp->next;
    }
    std::cout << "\nQueue after adding elements: ";
    temp = front;
    while (temp) {
        std::cout << temp->number << (temp->next == nullptr ? " " : "->");
        temp = temp->next;
    }
    std::cout << "\nAverage geometric: " << averageGeometic(front) << "\n";
    clearQueueNums(front);

	return 0;
}