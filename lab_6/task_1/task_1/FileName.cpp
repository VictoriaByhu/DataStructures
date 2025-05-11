/*Створити однозв’язний лінійний список із n елементів, які мають
два інформаційні поля: назва населеного пункту та відстань до нього з Києва.
Вивести на екран назви двох міст, найбільш віддалених від столиці. Додати в
список інформацію про будь-яке закордонне місто. Вивільнити динамічну
пам’ять.*/

#include <iostream>
using namespace std;

struct Locality
{
	string name;
	int distanceToKyiv;
	Locality* next;
};

void PushBack(Locality*& head, string name, int d)
{
	if (head == nullptr)
	{
		head = new Locality{ name, d, nullptr };
		return;
	}


	Locality* current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = new Locality{ name, d, nullptr };
}

void Show(Locality*& head)
{
	Locality* current = head;
	while (current != nullptr)
	{
		cout << current->name << " " << current->distanceToKyiv << endl;
		current = current->next;
	}
}

void Clear(Locality*& head)
{
	while (head != nullptr)
	{
		Locality* temp = head;
		head = head->next;
		delete temp;
	}
}

void MostDistantLocalities(Locality*& head)
{
	if (head == nullptr) return;

	Locality* current = head;
	int max1 = current->distanceToKyiv;

	while (current != nullptr)
	{
		if (current->distanceToKyiv > max1)
			max1 = current->distanceToKyiv;
		current = current->next;
	}

	current = head;
	int max2 = 0;

	while (current != nullptr)
	{
		if (current->distanceToKyiv < max1 && current->distanceToKyiv > max2)
			max2 = current->distanceToKyiv;
		current = current->next;
	}

	current = head;
	cout << "\nThe most distant localities to Kyiv:\n";
	while (current != nullptr)
	{
		if (current->distanceToKyiv == max1 || current->distanceToKyiv == max2)
			cout << current->name << "\n";

		current = current->next;
	}
}

int main()
{
	Locality* head = nullptr;

	Locality* cities[4] =
	{
		new Locality{ "Lviv", 462},
		new Locality{ "Chernivtsi", 402 },
		new Locality{ "Odessa", 445 },
		new Locality{ "Kharkiv", 422 }
	};

	for (int i = 0; i < 4; i++)
		PushBack(head, cities[i]->name, cities[i]->distanceToKyiv);

	Show(head);

	MostDistantLocalities(head);

	Clear(head);

	return 0;
}