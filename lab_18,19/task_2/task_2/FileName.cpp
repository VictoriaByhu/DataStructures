#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Звичайний алфавіт
const string alphabet = "abcdefghijklmnopqrstuvwxyz";

// Ключ для заміни (має бути тієї ж довжини!)
const string substitutionKey = "qwertyuiopasdfghjklzxcvbnm";

// Функція для пошуку індексу символа в алфавіті
int findIndex(char c, const string& reference) {
    for (int i = 0; i < reference.length(); ++i) {
        if (reference[i] == c) {
            return i;
        }
    }
    return -1; // Не знайдено
}

// Шифрування або дешифрування
string substituteText(const string& text, bool decrypt) {
    string result = "";
    for (int i = 0; i < text.length(); ++i) {
        char c = text[i];

        // Переводимо в нижній регістр
        char lowerC = tolower(c);
        bool isUpper = false;
        if (isupper(c)) {
            isUpper = true;
        }

        int index;
        if (decrypt == false) {
            index = findIndex(lowerC, alphabet);
            if (index != -1) {
                char newChar = substitutionKey[index];
                if (isUpper) {
                    newChar = toupper(newChar);
                }
                result += newChar;
            }
            else {
                result += c;
            }
        }
        else {
            index = findIndex(lowerC, substitutionKey);
            if (index != -1) {
                char newChar = alphabet[index];
                if (isUpper) {
                    newChar = toupper(newChar);
                }
                result += newChar;
            }
            else {
                result += c;
            }
        }
    }
    return result;
}

// Зчитування тексту
string readText(bool fromFile) {
    string text;
    if (fromFile) {
        string filename;
        cout << "Введіть назву файлу: ";
        cin >> filename;
        ifstream inFile(filename);
        if (inFile) {
            getline(inFile, text, '\0');
            inFile.close();
        }
        else {
            cout << "Не вдалося відкрити файл." << endl;
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
    cout << "1 - Шифрування\n2 - Дешифрування\nВаш вибір: ";
    cin >> mode;

    bool fromFile;
    cout << "Зчитати текст з файлу? (1 - так, 0 - ні): ";
    cin >> fromFile;

    string text = readText(fromFile);
    bool decrypt = false;
    if (mode == 2) {
        decrypt = true;
    }

    string result = substituteText(text, decrypt);

    if (decrypt == true) {
        cout << "Розшифрований текст:\n";
    }
    else {
        cout << "Зашифрований текст:\n";
    }

    cout << result << endl;

    return 0;
}
