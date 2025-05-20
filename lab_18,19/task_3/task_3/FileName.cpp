#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int ALPHABET_SIZE = 26;

// Функція для приведення символу до нижнього регістру
char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// Таблиця Віженера (для демонстрації)
void printVigenereTable() {
    cout << "ТАБЛИЦЯ ВІЖЕНЕРА (латиниця):\n";
    for (int row = 0; row < ALPHABET_SIZE; ++row) {
        for (int col = 0; col < ALPHABET_SIZE; ++col) {
            char ch = 'A' + (row + col) % ALPHABET_SIZE;
            cout << ch << " ";
        }
        cout << endl;
    }
}

// Розширення ключа до довжини тексту
string extendKey(const string& text, const string& key) {
    string result = "";
    int j = 0;
    for (int i = 0; i < text.length(); ++i) {
        char c = text[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            result += key[j % key.length()];
            j++;
        }
        else {
            result += ' '; // залишаємо місце для пропуску
        }
    }
    return result;
}

// Шифрування
string vigenereEncrypt(const string& text, const string& key) {
    string result = "";
    for (int i = 0; i < text.length(); ++i) {
        char c = text[i];
        char k = toLowerChar(key[i]);

        if (c >= 'A' && c <= 'Z') {
            int offset = (c - 'A' + (k - 'a')) % ALPHABET_SIZE;
            result += 'A' + offset;
        }
        else if (c >= 'a' && c <= 'z') {
            int offset = (c - 'a' + (k - 'a')) % ALPHABET_SIZE;
            result += 'a' + offset;
        }
        else {
            result += c;
        }
    }
    return result;
}

// Дешифрування
string vigenereDecrypt(const string& text, const string& key) {
    string result = "";
    for (int i = 0; i < text.length(); ++i) {
        char c = text[i];
        char k = toLowerChar(key[i]);

        if (c >= 'A' && c <= 'Z') {
            int offset = (c - 'A' - (k - 'a') + ALPHABET_SIZE) % ALPHABET_SIZE;
            result += 'A' + offset;
        }
        else if (c >= 'a' && c <= 'z') {
            int offset = (c - 'a' - (k - 'a') + ALPHABET_SIZE) % ALPHABET_SIZE;
            result += 'a' + offset;
        }
        else {
            result += c;
        }
    }
    return result;
}

int main() {
    int mode;
    cout << "1 - Шифрування\n2 - Дешифрування\nВаш вибір: ";
    cin >> mode;

    string text, key;
    cout << "Введіть текст: ";
    cin.ignore();
    getline(cin, text);

    cout << "Введіть ключове слово: ";
    getline(cin, key);

    string extendedKey = extendKey(text, key);
    string result;

    if (mode == 1) {
        result = vigenereEncrypt(text, extendedKey);
        cout << "Зашифрований текст:\n" << result << endl;
    }
    else if (mode == 2) {
        result = vigenereDecrypt(text, extendedKey);
        cout << "Розшифрований текст:\n" << result << endl;
    }
    else {
        cout << "Невірний вибір режиму." << endl;
        return 1;
    }

    cout << "\nБажаєш побачити таблицю Віженера? (1 - так, 0 - ні): ";
    int showTable;
    cin >> showTable;

    if (showTable == 1) {
        printVigenereTable();
    }

    return 0;
}
