#include <iostream>

using namespace std;

int main() {
	int a[15] = {10, 34, 5, 33, 1, 56, 23, 9 }, n = 8, min=a[0];


	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}

	cout << "Min value: " << min << endl;

	for (int i = 0; i < n; i++) {
		if (a[i] % 3 == 3) {
			n++;
			for (int j = n - 1; j > i; j--) {
				a[j] = a[j - 1];
			}
			a[i] = min;
			break;
		}
	}
		


	for (int i = 1; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}