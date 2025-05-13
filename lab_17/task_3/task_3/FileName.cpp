#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Прямий пошук (Naive) O((n-m + 1) * m)
int naiveSearch(const string& text, const string& pattern) {
    int n = text.length(), m = pattern.length();
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) ++j;
        if (j == m) return i;
    }
    return -1;
}

// Префікс-функція для Кнута-Морріса-Пратта
vector<int> prefixFunction(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        }
        else {
            if (len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
    return lps;
}

// KMP алгоритм
int KMPSearch(const string& text, const string& pattern) {
    int n = text.length(), m = pattern.length();
    vector<int> lps = prefixFunction(pattern);
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            ++i; ++j;
        }
        if (j == m) return i - j;
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1];
            else ++i;
        }
    }
    return -1;
}

// Алгоритм Бойєра-Мура (bad character heuristic)
int badCharBM(const string& text, const string& pattern) {
    const int ALPHABET = 256;
    int badChar[ALPHABET];
    int n = text.size(), m = pattern.size();

    for (int i = 0; i < ALPHABET; ++i)
        badChar[i] = -1;
    for (int i = 0; i < m; ++i)
        badChar[(unsigned char)pattern[i]] = i;

    int shift = 0;
    while (shift <= (n - m)) {
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

int main() {
    ifstream file("C:\\Users\\User\\Desktop\\uni\\data structures and algorithms\\lab_17\\task_3\\text.txt");
    if (!file.is_open()) {
        cout << "Error.\n";
        return 1;
    }

    string text, line;
    while (getline(file, line)) {
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
