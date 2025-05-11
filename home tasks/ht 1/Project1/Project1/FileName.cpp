#include <iostream>
using namespace std;

int main()
{
	int a[] = { 1, 10, 5, 7, 6, 34, 23, 0, 15, 25 }, i, j;
	int n = 10;

	cout << "Primary array: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			for (j = i; j < n; j++)
			{
				a[j] = a[j + 1];
				
			}
			i--; n--;
		}
	
	}

	cout << endl;
	cout << "======================================================" << endl;
	cout << "Edited array: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";


	cout << endl;
	cout << "======================================================" << endl;
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (a[j] < a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	cout << "Sorted array: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";









	return 0;
}