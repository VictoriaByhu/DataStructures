#include <iostream>
#include <vector>
using namespace std;

struct Activity 
{
    int index;
    int start;
    int end;
};

int main() 
{
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    for (int i = 0; i < n; ++i) 
    {
        cout << "Activity " << i + 1 << " - enter start and end time: ";
        cin >> activities[i].start >> activities[i].end;
        activities[i].index = i + 1;
    }

    //sort by end time
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (activities[j].end > activities[j + 1].end) 
            {
                swap(activities[j], activities[j + 1]);
            }
        }
    }

    // Choosing non-intersecting activities
    vector<Activity> selected;
    int lastEndTime = 0;

    for (int i = 0; i < n; ++i) 
    {
        if (activities[i].start >= lastEndTime)
        {
            selected.push_back(activities[i]);
            lastEndTime = activities[i].end;
        }
    }

    // Result output
    cout << "\nMax number of non-intersecting activities: " << selected.size() << endl;
    cout << "Selected activitied (index: start - end):\n";
    for (const auto& act : selected) 
    {
        cout << "Activity " << act.index << ": " << act.start << " - " << act.end << endl;
    }

    return 0;
}
