#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>


using namespace std;


bool isVowel(char ch) {
    ch = tolower(ch);
    return string("aeiouy").find(ch) != string::npos;
}

int main() {
    ifstream file("C:\\Users\\User\\Desktop\\uni\\data structures and algorithms\\lab_22\\task_2\\names.txt");
    vector<string> names;
    string line;

    
    while (getline(file, line)) {
        if (!line.empty()) {
            names.push_back(line);
        }
    }

    
    string key;
    cout << "Enter full name to search: ";
    getline(cin, key);

    //Counting occurrences
    int count = count_if(names.begin(), names.end(),
        [&key](const string& s) { return s == key; });
    cout << "Occurrences: " << count << endl;

    //Convert to uppercase letters
    for (auto& name : names)
        transform(name.begin(), name.end(), name.begin(), ::toupper);

    //Convert to lowercase letters
    for (auto& name : names)
        transform(name.begin(), name.end(), name.begin(), ::tolower);

    //Move names that start with a vowel forward
    stable_partition(names.begin(), names.end(),
        [](const string& s) { return isVowel(s[0]); });

    
    cout << "Processed names:\n";
    for (const auto& name : names)
        cout << name << '\n';

    return 0;
}
