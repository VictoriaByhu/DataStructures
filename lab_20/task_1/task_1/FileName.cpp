#include <iostream>
#include <cmath>
#include <iomanip> // для форматованого виводу
using namespace std;

const int N = 4; // кількість продуктів
double volume[N] = { 1, 1.5, 2, 0.5 }; // об'єм (дм³/кг)
double calories[N] = { 1500, 1500, 5000, 4000 }; // калорійність (ккал/кг)
double maxVolume = 45.0; // обмеження по об'єму
double maxWeight = 35.0; // обмеження по вазі

double bestCalories = 0;
double bestX[N];

void solve() {
    for (double meat = 0; meat <= maxWeight; meat += 0.5) { // м’ясо
        for (double flour = 0; flour <= maxWeight - meat; flour += 0.5) { // мука
            if (meat < flour * 2) continue; // м'яса у двічі більше за муку
            for (double milk = 0; milk <= maxWeight - meat - flour; milk += 0.5) { // молоко
                if (flour < milk) continue; // муки не менше, ніж молока
                for (double sugar = 0; sugar <= maxWeight - meat - flour - milk; sugar += 0.5) { // цукор
                    if (milk < 8 * sugar) continue; // молока хоча б у 8 разів більше, ніж цукру
                    double totalWeight = meat + flour + milk + sugar;
                    double totalVolume = meat * volume[0] + flour * volume[1] + milk * volume[2] + sugar * volume[3];
                    if (totalWeight <= maxWeight && totalVolume <= maxVolume) {
                        double totalCalories = meat * calories[0] + flour * calories[1] + milk * calories[2] + sugar * calories[3];
                        if (totalCalories > bestCalories) {
                            bestCalories = totalCalories;
                            bestX[0] = meat;
                            bestX[1] = flour;
                            bestX[2] = milk;
                            bestX[3] = sugar;
                        }
                    }
                }
            }
        }
    }

    cout << fixed << setprecision(2); // виводимо з точністю до 2 знаків
    cout << "Maximum calorie content: " << bestCalories << " kcal" << endl;
    cout << "Meat (kg): " << bestX[0] << endl;
    cout << "Flour (kg): " << bestX[1] << endl;
    cout << "Milk (kg): " << bestX[2] << endl;
    cout << "Sugar (kg): " << bestX[3] << endl;
}

int main() {
    solve(); 
    return 0;
}
