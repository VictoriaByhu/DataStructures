#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
string readTextFromFile(const string& filename) {
    ifstream file(filename);
    string line, result;
    while (getline(file, line)) {
        result += line + " ";
    }
    return result;
}

int main() {
    int mode;
    cout << "1 - Encrypt\n2 - Descrypt\nChoose: ";
    cin >> mode;
    
    int choice;
    string text;
    cout << "Input source:\n1. Manual\n2. File (text.txt)\nChoose: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "Enter text: ";
        getline(cin, text);
    }
    else if (choice == 2) {
        text = readTextFromFile("C:\\Users\\User\\Desktop\\uni\\data structures and algorithms\\lab_18,19\\task_1\\text.txt");
        cout << "Read from file: " << text << endl;
    }
    else {
        cout << "Invalid input source.\n";
        return 1;
    }

    if (mode == 1) {
        int shift;
        cout << "Enter the offset: ";
        cin >> shift;
        string result = caesarCipher(text, shift, false);
        cout << "Ciphertext:\n" << result << endl;

    }
    else if (mode == 2) {
        int shift;
        cout << "Enter the offset: ";
        cin >> shift;
        string result = caesarCipher(text, shift, true);
        cout << "Decrypted text:\n" << result << endl;

    }
    else {
        cout << "Wrong input.\n";
    }

    return 0;
}
