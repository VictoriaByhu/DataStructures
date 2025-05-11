#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void FillWithRand(int a[10][10], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 21;
        }
    }
}

void ShowMatrix(int a[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

void RemoveMainDiagonal(int a[10][10], int n, int** b) {
	int k = 0;
	int l = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
				b[k][l] = a[i][j];
                l++;
           }

        }
		l = 0;
        k++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
}

void FindRowWithMaxValue(int** b, int n, int& row) {
	int max = b[0][0];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (b[i][j] > max) {
				max = b[i][j];
				row = i;
			}
		}
	}
	

}

void RemoveRow(int** b, int** c, int& n, int row) {
    int k = 0;
	int l = 0;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (i != row) {
                c[k][l] = b[i][j];
                l++;
            }
        }
        l = 0;
        if (k < n - 1) {
            k++;
        }
       
    }
   

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << c[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int a[10][10];
    int n = 4;
    int row = 0;
    FillWithRand(a, n);
    ShowMatrix(a, n);

	int** b = new int* [n];
	for (int i = 0; i < n; i++) {
		b[i] = new int[n];
	}

    int** c = new int* [n];
    for (int i = 0; i < n; i++) {
        c[i] = new int[n];
    }

	RemoveMainDiagonal(a, n, b);
	FindRowWithMaxValue(b, n, row);
	cout << "Row with max value: " << row << endl;
	RemoveRow(b, c, n, row);

    


    return 0;
}
