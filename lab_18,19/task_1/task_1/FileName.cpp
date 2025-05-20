#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Знаходимо найчастішу букву
int findMostFrequentShift(const string& text) {
    int freq[26] = { 0 };

    for (int i = 0; i < text.length(); ++i) {
        char c = text[i];
        if (isalpha(c)) {
            if (isupper(c)) {
                freq[c - 'A']++;
            }
            else {
                freq[c - 'a']++;
            }
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < 26; ++i) {
        if (freq[i] > freq[maxIndex]) {
            maxIndex = i;
        }
    }

    // Найчастіша буква → вважаємо, що вона відповідає 'e'
    int shift = (maxIndex - ('e' - 'a') + 26) % 26;
    return shift;
}

// Основна функція шифрування або дешифрування
string caesarCipher(const string& text, int shift, bool decrypt) {
    string result = "";

    if (decrypt == true) {
        shift = -shift;
    }

    for (int i = 0; i < text.length(); ++i) {
        char c = text[i];

        if (isalpha(c)) {
            char base;
            if (isupper(c)) {
                base = 'A';
            }
            else {
                base = 'a';
            }

            int offset = c - base;
            int shifted = (offset + shift + 26) % 26;
            char newChar = base + shifted;
            result += newChar;
        }
        else {
            result += c;
        }
    }

    return result;
}

// Зчитування тексту
string readText(bool fromFile) {
    string text;
    if (fromFile == true) {
        string filename;
        cout << "Введіть назву файлу: ";
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
        cout << "Введіть зсув: ";
        cin >> shift;
        string result = caesarCipher(text, shift, false);
        cout << "Зашифрований текст:\n" << result << endl;

    }
    else if (mode == 2) {
        int shift;
        cout << "Введіть зсув: ";
        cin >> shift;
        string result = caesarCipher(text, shift, true);
        cout << "Розшифрований текст:\n" << result << endl;

    }
    else if (mode == 3) {
        int shift = findMostFrequentShift(text);
        cout << "Знайдений зсув: " << shift << endl;
        string result = caesarCipher(text, shift, true);
        cout << "Розшифрований текст:\n" << result << endl;

    }
    else {
        cout << "Невірний вибір режиму." << endl;
    }

    return 0;
}
