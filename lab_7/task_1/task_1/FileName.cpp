#include <iostream>
#include <cstdlib>
#include <iomanip>


struct Numbers {
    double number;
    Numbers* next;
}*top = nullptr;

void push(double number) {
    Numbers* newNumber = new Numbers;
    newNumber->number = number;
    newNumber->next = top;
    top = newNumber;
}


void fillStack(int size) {
    for (int i = 0; i < size; i++) {
        push((rand() % 171 - 60) / 10.0);
    }
}

void showStack(Numbers* top) {
    while (top != nullptr) {
        std::cout << top->number << " " ;
        top = top->next;
    }
    std::cout << "\n";
}

void popElements(Numbers*& top) {
    Numbers* temp = top;
    top = top->next;
    delete temp;
}

void deleteLowerThan(Numbers*& top, double value) {
    while (top != nullptr && top->number < value) {
        popElements(top);
    }

    if (top == nullptr) return;

    Numbers* temp = top;
    while (temp->next) {
        if (temp->next->number < value) {
            Numbers* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        else {
            temp = temp->next;
        }
    }
}

double getAverage(Numbers* top) {
    Numbers* temp = top;
    double sum = 0;
    int counter = 0;
    while (temp != nullptr) {
        sum += temp->number;
        counter++;
        temp = temp->next;
    }
    return sum / counter;
}

void clearStack() {
    Numbers* temp = top;
    while (temp) {
        Numbers* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    top = nullptr;
}

int main() {
   
    
    int amount = 5;
        fillStack(amount);
        std::cout << "Your stack: ";
        showStack(top);
        std::cout << "Enter number:\n";
        double number;
        std::cin >> number;
        deleteLowerThan(top, number);
        std::cout << "Stack after deleting elements lower than " << number << ":\n ";
        showStack(top);
        std::cout << "Average value: " << std::fixed << std::setprecision(2) << getAverage(top) << "\n";
        clearStack();
    

        return 0;
}
