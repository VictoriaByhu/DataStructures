#include <iostream>
using namespace std;

struct book {
	string name, author;
	int yearOfPublication, pages;
};

int main() {
	book books[] = {
		{"Shadows of consciousness", "Alexander Vetrov", 1970, 345},
		{"The paradox of reason", "Marina Sokolova", 2010, 200},
		{"Loneliness Code", "Dmytro Haiduk", 2002, 1000},
		{"Depth of illusions", "Anastasia Levchenko", 1999, 598}
	};
	int n = 4;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += books[i].pages;
		if (books[i].pages > 300 && books[i].yearOfPublication > 2000) {
			cout << books[i].name << endl
				<< books[i].author << endl
				<< books[i].yearOfPublication << endl
				<< books[i].pages << endl;
			cout << endl;
		}
	}

	cout << "Sum of pages: " << sum;

	return 0;
}