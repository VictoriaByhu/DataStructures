#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void printPlan(const vector<vector<int>>& plan, const vector<vector<int>>& cost) 
{
    int totalCost = 0;
    cout << "Optimal Delivery Plan:\n\n";
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

    cout << "\nMinimum Total Delivery Cost: " << totalCost << " currency units\n";
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
    vector<vector<bool>> used(ROWS, vector<bool>(COLS, false));

    int totalCells = ROWS * COLS;
    while (totalCells--) 
    {
        // Find the minimum cost cell that is not used yet
        int minCost = 1e9, row = -1, col = -1;
        for (int i = 0; i < ROWS; ++i)
        {
            for (int j = 0; j < COLS; ++j)
            {
                if (!used[i][j] && cost[i][j] < minCost && supply[i] > 0 && demand[j] > 0) 
                {
                    minCost = cost[i][j];
                    row = i;
                    col = j;
                }
            }
        }

        if (row == -1) break;

        int quantity = min(supply[row], demand[col]);
        plan[row][col] = quantity;
        supply[row] -= quantity;
        demand[col] -= quantity;

        if (supply[row] == 0)
            for (int j = 0; j < COLS; ++j) used[row][j] = true;
        if (demand[col] == 0)
            for (int i = 0; i < ROWS; ++i) used[i][col] = true;
    }

    printPlan(plan, cost);
    return 0;
}
