#include <iostream>
using namespace std;

const int SIZE = 10;

struct Time
{
	int hours;
	int minutes;
};



class Schedule
{
public:
	int trainNumber;
	string destinationStation;
	int distanceToStation;
	Time departureTime;
	Time arrivalTime;
	int journeyTime;

	void print() 
	{
		cout << "Train: " << trainNumber << endl 
			<< "Station: " << destinationStation << endl
			<< "Journey time: " << journeyTime << " min" << endl;
	}
};

int findLongestJourneyTime(Schedule train[], int SIZE)
{
	int longest = train[0].journeyTime;
	int index = 0;
	for (int i = 1; i < SIZE; i++)
	{
		if (train[i].journeyTime > longest)
		{
			longest = train[i].journeyTime;
			index = i;
		}
	}

	return index;

}

void quickSort(Schedule arr[], int first, int last) {
	int middle = arr[(first + last) / 2].journeyTime;
	int i = first;
	int j = last;

	do
	{
		while (arr[i].journeyTime < middle) i++;
		while (arr[j].journeyTime > middle) j--;
		
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
			
	} while (i <= j);

	if (first < j)
		quickSort(arr, first, j);
	if (i < last)
		quickSort(arr, i, last);

}

int main()
{
	Schedule train[SIZE] =
	{
		{101, "Lviv", 540, {8, 30}, {14, 0}, 330},
		{102, "Odesa", 480, {6, 15}, {12, 45}, 390},
		{103, "Kharkiv", 490, {7, 0}, {12, 0}, 300},
		{104, "Dnipro", 400, {9, 20}, {13, 40}, 260},
		{105, "Ternopil'", 430, {10, 50}, {16, 30}, 340},
		{106, "Poltava", 360, {5, 0}, {9, 30}, 270},
		{107, "Ivano-Frankivs'k", 600, {11, 10}, {17, 50}, 400},
		{108, "Chernihiv", 220, {12, 40}, {15, 20}, 160},
		{109, "Uzhgorod", 700, {13, 15}, {20, 0}, 405},
		{110, "Zaporizhzhia", 450, {14, 30}, {19, 0}, 270}
	};

	int maxTimeIdx = findLongestJourneyTime(train, SIZE);

	quickSort(train, 0, SIZE - 1);

	cout << "Info of train that has longest journey time:\n";

	train[SIZE - 1].print();

	return 0;
}