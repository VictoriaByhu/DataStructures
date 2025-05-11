#include <iostream>
using namespace std;

class TV
{
public:
	string brand;
	int screenSize;
	double price; 
};

void shellSortBySize(TV arr[], int n) 
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++) 
        {
            TV temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].screenSize > temp.screenSize; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void gnomeSortByPrice(TV arr[], int start, int end) 
{
    int index = start + 1;
    while (index <= end) 
    {
        if (index == start || arr[index].price <= arr[index - 1].price) 
            index++;
        else 
        {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
}

void printTVs(TV arr[], int n) 
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].brand << ", "
            << arr[i].screenSize << "\", "
            << arr[i].price << " UAH\n";
    }
    cout << "----------------------\n";
}

int main()
{
    const int n = 10;
    TV tvs[n] = 
    {
        {"Samsung", 45, 15999.99},
        {"LG", 32, 8999.50},
        {"Sony", 60, 32999.00},
        {"Panasonic", 45, 14999.00},
        {"Toshiba", 32, 7999.99},
        {"Philips", 60, 27999.99},
        {"Xiaomi", 45, 13999.49},
        {"Sharp", 60, 31999.00},
        {"Hisense", 32, 9499.00},
        {"JVC", 60, 29999.00}
    };

    shellSortBySize(tvs, n);

    int i = 0;
    while (i < n) 
    {
        int size = tvs[i].screenSize; 
        int j = i;
        while (j < n && tvs[j].screenSize == size) j++;
        gnomeSortByPrice(tvs, i, j - 1);
        i = j;
    }

    cout << "Sorted list:\n";
    printTVs(tvs, n);

	return 0;
}