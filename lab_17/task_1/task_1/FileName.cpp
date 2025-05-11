#include <iostream>
#include <vector>
using namespace std;

struct Marks
{
public:
	int higherMath;
	int programming;
	int history;
};

struct Student
{
public:
	string Name;
	Marks marks;
	double averageMark = calculateAverage();

	Student(string name, Marks m)
	{
		Name = name;
		marks = m;
		averageMark = calculateAverage();
	}

	double calculateAverage()
	{
		double average = (marks.higherMath + marks.history + marks.programming) / 3.0;
		return average;
	}
};

double findMaxAverage(Student student[], int SIZE)
{
	double max = student[0].averageMark;
	for (int i = 1; i < SIZE; i++)
	{
		if (student[i].averageMark > max)
			max = student[i].averageMark;
	}

	return max;
}

void showMatchingStudents(Student student[], int SIZE, double max)
{
	vector<int> indexes;
	int count = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (student[i].averageMark == max)
		{
			count++;
			indexes.push_back(i);
		}
	}

	cout << "Count and indexes of students that have max average mark:\n" 
		<< "Count: " << count << endl
		<< "Indexes: ";
	for (int idx : indexes)
	{
		cout << idx << " ";
	}


}

int main()
{
	const int SIZE = 10;
	Student student[SIZE] =
	{
		{"Anna Kovalchuk", {94, 85, 60}},
		{"Maksym Doroshenko", {70, 80, 72}},
		{"Iryna Melnyk", {92, 86, 88}},
		{"Oleksandr Shevchenko", {88, 91, 77}},
		{"Mariia Tkachenko", {92, 86, 88}},
		{"Vladyslav Lytvyn", {67, 79, 81}},
		{"Sofiia Humeniuk", {92, 86, 88}},
		{"Dmytro Savchenko", {75, 90, 83}},
		{"Alina Ostapenko", {89, 70, 65}},
		{"Yehor Kuzmenko", {78, 88, 93}}
	};

	for (int i = 0; i < 10; i++)
	{
		cout << student[i].Name << " - Average Mark: " << student[i].averageMark << endl;
	}
	cout << "-------------------------------------\n";

	double max = findMaxAverage(student, SIZE);

	showMatchingStudents(student, SIZE, max);

	return 0;
}