#include <iostream>
#include <iomanip>
#include <cmath>

struct Compositions {
    std::string holder;
    std::string name;
    std::string author;
    double price;
    double duration;
    int numberOfCopies;
    Compositions* next;
}*compositionsTop = nullptr;



Compositions samples[5] = 
{
    {"CD", "Symphony No. 5", "Beethoven", 10.99, 35.5, 100, nullptr },
    { "Vinyl", "The Four Seasons", "Vivaldi", 15.50, 40.0, 50, nullptr },
    { "Tape", "Moonlight Sonata", "Beethoven", 12.75, 30.0, 75, nullptr },
    { "Digital", "Clair de Lune", "Debussy", 8.99, 25.0, 200, nullptr },
    { "Streaming", "The Nutcracker Suite", "Tchaikovsky", 20.00, 50.0, 10, nullptr }
};



void pushComposition(Compositions samples[], int numberOfCopies) 
{
    Compositions* newComposition = new Compositions;
    newComposition->holder = samples->holder;
    newComposition->name = samples->name;
    newComposition->duration = samples->duration;
    newComposition->price = samples->price;
    newComposition->author = samples->author;
    newComposition->numberOfCopies = numberOfCopies;
    newComposition->next = compositionsTop;
    compositionsTop = newComposition;
}

void fillCompositions(int size) 
{
    for (int i = 0; i < size; i++) 
    {
        pushComposition(&samples[i], rand() % 100 + 1);
    }
}

void showCompositions(Compositions* compositionsTop) 
{
    while (compositionsTop) 
    {
        std::cout << "Holder: " << compositionsTop->holder << ", Name: " << compositionsTop->name << ", Author: " << compositionsTop->author << ", Price: " << std::fixed << std::setprecision(2) << compositionsTop->price << ", Duration: " << compositionsTop->duration << ", Number of Copies: " << compositionsTop->numberOfCopies << "\n";
        compositionsTop = compositionsTop->next;
    }
    std::cout << "\n";
}

double allTime(Compositions* compositionsTop, std::string name = "Beethoven") 
{
    Compositions* temp = compositionsTop;
    double sum = 0;
    while (temp) 
    {
        if (temp->author == name) 
        {
            sum += temp->duration * temp->numberOfCopies;
        }
        temp = temp->next;
    }
    return sum;
}
double avgPrice(Compositions* compositionsTop, std::string holder = "Tape") 
{
    Compositions* temp = compositionsTop;
    double sum = 0;
    int counter = 0;
    while (temp) 
    {
        if (temp->holder == holder) 
        {
            counter++;
            sum += temp->price * temp->numberOfCopies;
        }
        temp = temp->next;
    }
    return sum / counter;
}

void popCompositions(Compositions* compositionsTop) 
{
    Compositions* temp = compositionsTop;
    compositionsTop = compositionsTop->next;
    delete temp;
}

void clearCompositions(Compositions* compositionsTop) 
{
    Compositions* temp = compositionsTop;
    while (temp) 
    {
        Compositions* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    compositionsTop = nullptr;
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
    fillCompositions(num);
    std::cout << "Your list: \n";
    showCompositions(compositionsTop);
    std::cout << "Total time of all compositions by Beethoven: " << allTime(compositionsTop) << "\n";
    std::cout << "Average price of all compositions on Tape: " << avgPrice(compositionsTop) << "\n";
    clearCompositions(compositionsTop);
}