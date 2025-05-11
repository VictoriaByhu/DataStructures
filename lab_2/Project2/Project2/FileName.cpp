#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillUniqueRand(int a[], int n) {
    srand(time(0));
    for (int i = 0; i < n; ) {
        int num = rand() % 51;
        bool exists = false;
        for (int j = 0; j < i; j++) {
            if (a[j] == num) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            a[i] = num;
            i++;
        }
    }
}

void showArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void filterArrayAndAddZero(int a[], int n, int x) {
    int* b = new int[n];
    int m = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            b[m++] = a[i];
        }
    }

    while (m < n) {
        b[m++] = 0;
    }

    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }

    delete[] b;
}

int main() {
    int n = 10;
    int a[10];

    fillUniqueRand(a, n);
    cout << "Initial array: ";
    showArray(a, n);

    int x;
    cout << "Enter X: ";
    cin >> x;

    filterArrayAndAddZero(a, n, x);
    cout << "Filtered array: ";
    showArray(a, n);

    return 0;
}
