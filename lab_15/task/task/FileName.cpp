#include <iostream>
#include <ctime>
#include <vector>
using namespace std;



void showArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void bubbleSort(vector<int>& arr)
{
	int size = arr.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

void insertionSort(vector<int>& arr)
{
	int size = arr.size();
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void selectionSort(vector<int>& arr)
{
	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		int minIdx = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}
		swap(arr[minIdx], arr[i]);
	}
}

void gnomeSort(vector<int>& arr)
{
	int size = arr.size();
	int idx = 0;
	while (idx < size)
	{
		if (idx == 0)
			idx++;
		if (arr[idx] >= arr[idx - 1])
			idx++;
		else
		{
			swap(arr[idx], arr[idx - 1]);
			idx--;
		}
	}
}

void heapify(vector<int>& arr, int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(vector<int>& arr) {
	int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void merge(vector<int>& arr, int leftIndex, int midIndex, int rightIndex) {
	int leftArraySize = midIndex - leftIndex + 1;
	int rightArraySize = rightIndex - midIndex;
	vector<int> L(leftArraySize), R(rightArraySize);
	for (int i = 0; i < leftArraySize; i++)
		L[i] = arr[leftIndex + i];
	for (int j = 0; j < rightArraySize; j++)
		R[j] = arr[midIndex + 1 + j];
	int i = 0, j = 0, index = leftIndex;
	while (i < leftArraySize && j < rightArraySize) {
		if (L[i] <= R[j])
		{
			arr[index] = L[i];
			index++;
			i++;
		}
		else
		{
			arr[index] = R[j];
			index++;
			j++;
		}
			
	}
	while (i < leftArraySize)
	{
		arr[index] = L[i];
		index++;
		i++;
	}
	while (j < rightArraySize)
	{
		arr[index] = R[j];
		index++;
		j++;
	}
}

void mergeSort(vector<int>& arr, int leftIndex, int rightIndex) {
	if (leftIndex < rightIndex) {
		int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
		mergeSort(arr, leftIndex, midIndex);
		mergeSort(arr, midIndex + 1, rightIndex);
		merge(arr, leftIndex, midIndex, rightIndex);
	}
}

template <typename Func>
double measureTime(Func sortFunc, vector<int> arr) {
	clock_t start = clock();
	sortFunc(arr);
	clock_t end = clock();
	return (double)(end - start) / CLOCKS_PER_SEC;
}


int main()
{
	srand(time(0));
	int sizes[] = { 10, 100, 1000 };

	const int max = 50;
	const int min = 1;

	for (int s = 0; s < 3; s++) {
		int n = sizes[s];
		vector<int> array(n);
		for (int i = 0; i < n; i++)
			array[i] = rand() % (max - min) + 1;;

		cout << "n = " << n << endl;
		cout << "1. Bubble Sort:    " << measureTime(bubbleSort, array) << " seconds" << endl;
		cout << "2. Insertion Sort: " << measureTime(insertionSort, array) << " seconds" << endl;
		cout << "3. Selection Sort: " << measureTime(selectionSort, array) << " seconds" << endl;
		cout << "4. Gnome Sort:     " << measureTime(gnomeSort, array) << " seconds" << endl;
		cout << "5. Heap Sort:      " << measureTime(heapSort, array) << " seconds" << endl;

		int size = sizeof(array) / sizeof(array[0]);
		int leftIndex = 0;
		int rightIndex = size - 1;
		int midIndex = (size / 2) - 1;
		vector<int> mergeArr = array;
		clock_t start = clock();
		mergeSort(mergeArr, leftIndex, midIndex, rightIndex);
		clock_t end = clock();
		cout << "8. Merge Sort:     " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;



		cout << "-----------------------------" << endl;
	}




	return 0;
}