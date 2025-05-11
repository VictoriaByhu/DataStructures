#include <iostream>
using namespace std;

void MakingNewArray(int arr[], int n, int newArr[]) {
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			newArr[index] = arr[i];
			index++;
		}
			
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			newArr[index] = arr[i];
			index++;
		}
			
	}
	cout << "New array: ";
	for (int i = 0; i < index; i++) {
		cout << newArr[i] << " ";
	}
	cout << endl;
}

void BubbleSort(int newArr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= i; j--) {
			if (newArr[j] % 2 != 0 && newArr[j - 1] % 2 != 0) {
				if (newArr[j] > newArr[j-1]) {
					swap(newArr[j], newArr[j - 1]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (newArr[j] % 2 == 0 && newArr[j + 1] % 2 == 0) {
				if (newArr[j] > newArr[j + 1]) {
					swap(newArr[j], newArr[j + 1]);
				}
			}
		}
	}
		

	for (int i = 0; i < n; i++) {
		cout << newArr[i] << " ";
	}

}

int main() {
	int arr[10] = { 1, 5, 4, 3, 6, 7, 2, 8, 9, 0 };
	int n=10;
	int newArr[10];
	
	cout << "Cheking the array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	MakingNewArray(arr, n, newArr);
	cout << "Sorted array: ";
	BubbleSort(newArr, n);
	

	


	return 0;
}
