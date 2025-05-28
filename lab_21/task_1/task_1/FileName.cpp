#include <iostream>
#include <iomanip>
using namespace std;

struct Staff 
{
    string position;
    int coefficient;
    int count;
    double salary;
    double totaSalary;
};

int main() 
{
    const int n = 8;
    double totalFund = 380000;
    Staff staff[n] =
    {
        {"Cleaner", 1, 7},
        {"Nurse", 2, 10},
        {"Doctor", 3, 10},
        {"Pharmacy Head", 3, 1},
        {"Department Head", 4, 3},
        {"Chief Doctor", 5, 1},
        {"Logistics Manager", 3, 1},
        {"Hospital Manager", 3, 1}
    };

    int totalCoeff = 0;
    for (int i = 0; i < n; ++i)
    {
        totalCoeff += staff[i].coefficient * staff[i].count;
    }

    double baseSalary = totalFund / totalCoeff;

    cout << fixed << setprecision(2);
    cout << "Base salary (cleaner): " << baseSalary << " UAH\n\n";
    cout << left << setw(20) << "Position" << setw(10) << "Count"
        << setw(15) << "Salary" << setw(20) << "Total Salary" << endl;

    for (int i = 0; i < n; ++i)
    {
        staff[i].salary = baseSalary * staff[i].coefficient;
        staff[i].totaSalary = staff[i].salary * staff[i].count;

        cout << setw(20) << staff[i].position
            << setw(10) << staff[i].count
            << setw(15) << staff[i].salary
            << setw(20) << staff[i].totaSalary << endl;
    }

    return 0;
}