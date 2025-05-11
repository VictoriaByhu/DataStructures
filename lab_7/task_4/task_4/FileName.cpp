#include <iostream>

struct volleyballQueue {
    std::string commandName;
    std::string city;
    int numberOfPoints;
    volleyballQueue* next;
}*vFront = nullptr, * vRear = nullptr;

std::string cities[5] = { "New York", "Los Angeles", "Chicago", "Houston", "Phoenix" };
std::string commands[5] = { "Serve", "Set", "Spike", "Block", "Dig" };

void vEnqueue(std::string name, std::string city, int points) {
    volleyballQueue* newCommand = new volleyballQueue;
    newCommand->commandName = name;
    newCommand->city = city;
    newCommand->numberOfPoints = points;
    newCommand->next = nullptr;
    if (vRear == nullptr) {
        vFront = vRear = newCommand;
        return;
    }
    vRear->next = newCommand;
    vRear = newCommand;
}

void fillVolleyballQueue(int size) {
    for (int i = 0; i < size; i++) {
        vEnqueue(commands[rand() % 5], cities[rand() % 5], rand() % 100 + 1);
    }

}

void clearQueueVolleyball(volleyballQueue*& vFront) {
    volleyballQueue* temp = vFront;
    while (temp) {
        volleyballQueue* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    vFront = nullptr;
    vRear = nullptr;
}

int main() {
    int size;
    std::cout << "Enter number of elements in list:\n";
    std::cin >> size;
    while (size <= 0) {
        std::cout << "List should contain at least 1 element\n";
        std::cout << "Enter number of elements in list:\n";
        std::cin >> size;
    }
    fillVolleyballQueue(size);
    std::cout << "Your queue:\n";
    volleyballQueue* temp = vFront;
    int winner = temp->numberOfPoints, outsider = temp->numberOfPoints;
    while (temp) {
        if (temp->numberOfPoints > winner) {
            winner = temp->numberOfPoints;
        }
        if (temp->numberOfPoints < outsider) {
            outsider = temp->numberOfPoints;
        }
        std::cout << "Command: " << temp->commandName << ", City: " << temp->city << ", Number of points: " << temp->numberOfPoints << "\n";
        temp = temp->next;
    }
    std::cout << "Cities from which commands were taken:\n";

    for (int i = 0; i < 5; i++) {
        bool alreadyExists = false;
        temp = vFront;
        while (temp)
        {
            if (temp->city == cities[i] && !alreadyExists) {
                std::cout << cities[i] << " ";
                alreadyExists = true;
                break;
            }
            temp = temp->next;
        }
    }
    std::cout << "\n";
    temp = vFront;
    while (temp) {
        if (temp->numberOfPoints == winner) {
            std::cout << "Winner: " << temp->commandName << ", City: " << temp->city << ", Number of points: " << temp->numberOfPoints << "\n";
        }
        if (temp->numberOfPoints == outsider) {
            std::cout << "Outsider: " << temp->commandName << ", City: " << temp->city << ", Number of points: " << temp->numberOfPoints << "\n";
        }
        temp = temp->next;
    }
    clearQueueVolleyball(vFront);

	return 0;
}