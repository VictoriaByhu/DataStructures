#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>
using namespace std;

// Функція шифрування/дешифрування Цезаря
string caesarCipher(const string& text, int shift, bool decrypt = false) {
    string result = "";
    if (decrypt) shift = -shift;

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + shift + 26) % 26 + base;
        }
        result += c;
    }
    return result;
}

// Частотний аналіз
int frequencyDecrypt(const string& cipherText) {
    map<char, int> freq;
    for (char c : cipherText) {
        if (isalpha(c)) freq[tolower(c)]++;
    }

    // Найчастіше вживана літера в англ мові — 'e'
    char mostFrequent = max_element(freq.begin(), freq.end(),
        [](auto& a, auto& b) { return a.second < b.second; })->first;

    int shift = (mostFrequent - 'e' + 26) % 26;
    return shift;
}

string readText(bool fromFile) {
    string text;
    if (fromFile) {
        string filename;
        cout << "Введіть ім'я файлу: ";
        cin >> filename;
        ifstream inFile(filename);
        if (inFile) {
            getline(inFile, text, '\0');
            inFile.close();
        }
        else {
            cout << "Не вдалося відкрити файл.\n";
        }
    }
    else {
        cout << "Введіть текст: ";
        cin.ignore();
        getline(cin, text);
    }
    return text;
}

int main() {
    int mode;
    cout << "1 - Шифрування\n2 - Дешифрування (зсув)\n3 - Дешифрування (частотний метод)\nВаш вибір: ";
    cin >> mode;

    bool fromFile;
    cout << "Зчитати текст з файлу? (1 - так, 0 - ні): ";
    cin >> fromFile;
    string text = readText(fromFile);

    if (mode == 1) {
        int shift;
        cout << "Введіть крок зсуву (може бути від’ємним): ";
        cin >> shift;
        cout << "Зашифрований текст: " << caesarCipher(text, shift) << endl;
    }
    else if (mode == 2) {
        int shift;
        cout << "Введіть крок зсуву для дешифрування: ";
        cin >> shift;
        cout << "Дешифрований текст: " << caesarCipher(text, shift, true) << endl;
    }
    else if (mode == 3) {
        int shift = frequencyDecrypt(text);
        cout << "Знайдений зсув: " << shift << endl;
        cout << "Дешифрований текст: " << caesarCipher(text, shift, true) << endl;
    }
    else {
        cout << "Невірний режим.\n";
    }

    return 0;
}
