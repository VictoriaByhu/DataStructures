#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void printPlan(const vector<vector<int>>& plan, const vector<vector<int>>& cost) 
{
    int totalCost = 0;
    cout << "Delivery Plan (North-West Corner Method):\n\n";
    cout << "     M1  M2  M3\n";
    for (int i = 0; i < ROWS; ++i) 
    {
        cout << "S" << i + 1 << " |";
        for (int j = 0; j < COLS; ++j) 
        {
            if (plan[i][j] != 0)
                cout << setw(3) << plan[i][j] << " ";
            else
                cout << setw(3) << "- ";
        }
        cout << "\n";
    }

    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            totalCost += plan[i][j] * cost[i][j];

    cout << "\nTotal Delivery Cost: " << totalCost << " currency units\n";
}

int main() 
{
    vector<vector<int>> cost = 
    {
        {8, 7, 2},
        {6, 3, 4},
        {3, 8, 1}
    };

    vector<int> supply = { 1500, 1900, 1600 };
    vector<int> demand = { 1800, 1200, 2000 };

    vector<vector<int>> plan(ROWS, vector<int>(COLS, 0));

    int i = 0, j = 0;
    while (i < ROWS && j < COLS) 
    {
        int quantity = min(supply[i], demand[j]);
        plan[i][j] = quantity;
        supply[i] -= quantity;
        demand[j] -= quantity;

        if (supply[i] == 0) ++i;
        else if (demand[j] == 0) ++j;
    }

    printPlan(plan, cost);
    return 0;
}
