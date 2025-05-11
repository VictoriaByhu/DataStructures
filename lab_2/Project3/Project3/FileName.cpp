#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;



void PrintMatrix(int a[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "---------------------\n";
}
bool IsUnique(int a[5][5], int num) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (a[i][j] == num)
                return false;
    return true;
}

void FillMatrix(int a[5][5]) {
    srand(time(0));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int num;
            do {
                num = rand() % 26; 
            } while (!IsUnique(a, num));
            a[i][j] = num;
        }
    }
}

int main() {
    int a[5][5];
    srand(time(0));
   
    
    FillMatrix(a);
    PrintMatrix(a);

    int maxRow = 0, maxCol = 0;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (a[i][j] > a[maxRow][maxCol])
                maxRow = i, maxCol = j;

    for (int j = 0; j < 5; j++)
        swap(a[0][j], a[maxRow][j]);

    PrintMatrix(a);

    for (int i = 0; i < 5; i++)
        swap(a[i][0], a[i][maxCol]);

    PrintMatrix(a);

    return 0;
}

