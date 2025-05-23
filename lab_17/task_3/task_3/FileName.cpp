#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int naiveSearch(const string& text, const string& pattern) 
{
    int n = text.length(), m = pattern.length();
    for (int i = 0; i <= n - m; ++i) 
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) ++j;
        if (j == m) return i;
    }
    return -1;
}


vector<int> prefixFunction(const string& pattern) 
{
    int m = pattern.length();
    vector<int> vector(m, 0);
    int j = 0;
    for (int i = 1; i < m; ) 
    {
        if (pattern[i] == pattern[j]) 
        {
            vector[i++] = ++j;
        }
        else 
        {
            if (j != 0) j = vector[j - 1];
            else vector[i++] = 0;
        }
    }
    return vector;
}


int KMPSearch(const string& text, const string& pattern) 
{
    int n = text.length(), m = pattern.length();
    vector<int> lps = prefixFunction(pattern);
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) 
        {
            ++i; ++j;
        }
        if (j == m) return i - j;
        else if (i < n && text[i] != pattern[j]) 
        {
            if (j != 0) j = lps[j - 1];
            else ++i;
        }
    }
    return -1;
}


int badCharBM(const string& text, const string& pattern) 
{
    const int ALPHABET = 256;
    int badChar[ALPHABET];
    int n = text.size(), m = pattern.size();

    for (int i = 0; i < ALPHABET; ++i)
        badChar[i] = -1;
    for (int i = 0; i < m; ++i)
        badChar[(unsigned char)pattern[i]] = i;

    int shift = 0;
    while (shift <= (n - m)) 
    {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;
        if (j < 0)
            return shift;
        else
            shift += max(1, j - badChar[(unsigned char)text[shift + j]]);
    }
    return -1;
}

int main() 
{
    ifstream file("C:\\Users\\User\\Desktop\\DataStructures\\lab_17\\task_3\\text.txt");
    if (!file.is_open()) 
    {
        cout << "Error.\n";
        return 1;
    }

    string text, line;
    while (getline(file, line)) 
    {
        text += line + " ";
    }
    file.close();

    string pattern;
    cout << "Enter a line to search: ";
    getline(cin, pattern);

    int index1 = naiveSearch(text, pattern);
    int index2 = KMPSearch(text, pattern);
    int index3 = badCharBM(text, pattern);

    cout << "\nSearching result:\n";

    cout << "1. Naive search: ";
    if (index1 != -1)
    {
        cout << "Found at position " << index1 << endl;
    }
    else
    {
        cout << "Substring not found\n";
    }

        

    cout << "2. Knuth-Morris-Pratt: ";
    if (index2 != -1)
    {
        cout << "Found at position " << index2 << endl;
    }
    else
    {
        cout << "Substring not found\n";
    }

    cout << "3. Boyer-Moore: ";
    if (index3 != -1)
    {
        cout << "Found at position " << index3 << endl;
    }
    else
    {
        cout << "Substring not found\n";
    }

    return 0;
}
