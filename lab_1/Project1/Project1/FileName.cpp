#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <fstream>
using namespace std;

void isArrayMultiple(int n)
{
	if (n % 4 == 0)
		cout << "Array is multiple of four" << endl;
	else
		cout << "Array isn't multiple of four" << endl;

}
void arrayFilling(float a[], int n, int max, int min)
{
	srand(time(0));
	//заповнюЇмо одновим≥рний масив рандомними числами з в≥др≥зка [-1.50; 4.50]
	for (int i = 0; i < n; i++)
		a[i] = (min + rand() % (max - min + 1)) / 100.0;
}

void printArray(float a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}


	

void bubbleSort(float a[], int n, int choise) {
	if (choise == 1) {
		float temp1 = a[0];
		for (int i = 0; i < n; i++) {
			for (int j = n-1; j >= i; j--) {
				
				if (a[j] < a[j-1]) {
					temp1 = a[j - 1];
					a[j - 1] = a[j];
					a[j] = temp1;
				}
				
			}
			

		}
		cout << "\nAscending: \n" << endl;
		for (int i = 0; i < n; i++) {

			cout << a[i] << " ";
			
			
		}
		cout << endl;

	}
	if (choise == 2) {
		float temp2 = a[0];
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j > i; j--) {

				if (a[j] > a[j - 1]) {
					temp2 = a[j - 1];
					a[j - 1] = a[j];
					a[j] = temp2;
				}

			}


		}
		cout << "\nDiscending: \n" << endl;
		for (int i = 0; i < n; i++) {

			cout << a[i] << " ";

			
		}
		cout << endl;
	}
	
}

void maxValue (float a[], int n) {
	float max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	cout << "Max value of 1D array: " << max << endl;
}

int main()
{
	int min = -150, max = 450;
	int sizes[] = { 20, 100, 1000 };

	ofstream file("output.txt");
	if (!file) {
		cerr << "Error" << endl;
		return 1;
	}

	for (int version = 0; version < 3; version++) {
		int n = sizes[version];
		if (n % 4 != 0) continue;

		clock_t globalStart = clock();
		float* a = new float[n];
		arrayFilling(a, n, max, min);
		printArray(a, n);

		cout << endl;
		cout << "==========================================================================================" << endl;

		float** b = new float* [n / 4]; // ¬ид≥ленн€ памТ€т≥ дл€ р€дк≥в
		for (int i = 0; i < n / 4; i++) {
			b[i] = new float[4]; // ¬ид≥ленн€ памТ€т≥ дл€ кожного стовпц€
		}

		int index = 0;
		//перетворюЇмо одновим≥рний масив у двовим≥рний
		for (int i = 0; i < n / 4; i++) {
			for (int j = 0; j < 4; j++) {
				b[i][j] = a[index++];
			}
		}

		for (int i = 0; i < n / 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << b[i][j] << "\t";
			}
			cout << endl;
		}



		cout << "==========================================================================================" << endl;
		//тут матриц€ сортуЇтьс€ за зростанн€м
		float temp1 = b[0][0];
		for (int i = 0; i < n / 4; i++) {
			if (i % 2 == 0) {
				for (int j = 1; j < 4; j++) {
					for (int k = 4 - 1; k >= j; k--) {
						if (b[i][k] < b[i][k - 1]) {
							temp1 = b[i][k - 1];
							b[i][k - 1] = b[i][k];
							b[i][k] = temp1;
						}
					}
				}
			}

		}
		cout << "\nAscending: \n" << endl;
		for (int i = 0; i < n / 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << b[i][j] << "\t";
			}
			cout << endl;
		}

		cout << "==========================================================================================" << endl;
		//тут матриц€ сортуЇтьс€ за спаданн€м
		float temp2 = b[0][0];
		for (int i = 0; i < n / 4; i++) {
			if (i % 2 != 0) {
				for (int j = 1; j < 4; j++) {
					for (int k = 4 - 1; k >= j; k--) {
						if (b[i][k] > b[i][k - 1]) {
							temp2 = b[i][k - 1];
							b[i][k - 1] = b[i][k];
							b[i][k] = temp2;
						}
					}
				}
			}

		}

		cout << "\nDiscending: \n" << endl;
		for (int i = 0; i < n / 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << b[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "==========================================================================================" << endl;
		//тут сортуЇтьс€ одновим≥рний масив
		int choise = 0;
		cout << "How do you wanna sort one-dimensional array? \n 1. ascending \n 2. descending\n" << endl;
		cin >> choise;

		while (choise != 1 && choise != 2) {
			cout << "There is no such option" << endl;
			cout << "How do you wanna sort your array? \n 1. ascending \n 2. descending\n" << endl;
			cin >> choise;

		}

		bubbleSort(a, n, choise);
		cout << "==========================================================================================" << endl;
		//тут знаходитьс€ максимальний елемент одновим≥рного масиву

		maxValue(a, n);

		cout << "==========================================================================================" << endl;
		//тут знаходитьс€ максимальний елемент кожного стовпц€
		float maxVal[4] = { b[0][0], b[0][1], b[0][2], b[0][3] };

		for (int j = 0; j < 4; j++) {
			for (int i = 1; i < n / 4; i++) {
				if (b[i][j] > maxVal[j]) {
					maxVal[j] = b[i][j];

				}
			}
		}

		for (int j = 0; j < 4; j++)
		{
			cout << "Max value in column " << j << ": " << maxVal[j] << endl;
		}

		cout << "==========================================================================================" << endl;

		isArrayMultiple(n);

	
	    clock_t globalEnd = clock();
		double totalElapsedTime = double(globalEnd - globalStart) / CLOCKS_PER_SEC;
		size_t totalMemory = n * sizeof(a) + n * sizeof(b);
			

		file << "Execution time for n=" << n << ": " << totalElapsedTime<<"\n";
		file << "Memory used for n=" << n << ": " << totalMemory<<"\n";
	}
		

		
		
		file.close();
	
	  
	

	return 0;
}