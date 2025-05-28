#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool descendingSort(int a, int b)
{
    return a > b;
}

int main()
{
	ifstream file("C:\\Users\\User\\Desktop\\uni\\data structures and algorithms\\lab_22\\task_1\\numbers.txt");
    int n, x;
    cout << "Enter the number of numbers to process: ";
    cin >> n;

    //filling the vector
    vector<int> vec;
    while (file >> x && vec.size() < n) 
    {
        vec.push_back(x);
    }
    
    size_t part = vec.size() / 3;
    sort(vec.begin(), vec.begin() + part, descendingSort);//the first third

    sort(vec.begin() + part * 2, vec.end());//the last third

    cout << "\nThe first vector after sort:\n";
    for (auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

    vec.erase(unique(vec.begin(), vec.end()), vec.end());//removing consecutive duplicates
    cout << "\nThe first vector after removing consecutive duplicates:\n";
    for (auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

    stable_partition(vec.begin(), vec.end(), [](int n) {return n > 10; });

    

    cout << "\nParted vector by numbers greater and lower than 10:\n";
    for (auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

    for (auto& x : vec)
    {
        if (x > 10)
        {
            x += 100;
        }
    }

    cout << "\nThe first part increased by 100:\n";
    for (auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

    auto maxElement = max_element(vec.begin(), vec.end());
    auto minElement = min_element(vec.begin(), vec.end());

    for (auto& x : vec)
    {
        if (x > 100)
        {
            x = *maxElement;
        }
        else if (x < -100)
        {
            x = *minElement;
        }
    }
    
    cout << "\nElements greater than 100 replaced with max element and lower than -100 replaced with min element:\n";
    for (auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

    vec.erase(remove_if(vec.begin(), vec.end(), [](int v) { return v >= -5 && v <= 5; }), vec.end());//elements removal from the range [-5;5];

    cout << "\nVector after removing elements from the range [-5;5]:\n";
    for (auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;

	return 0;
}