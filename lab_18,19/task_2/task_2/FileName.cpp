#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const string alphabet = "abcdefghijklmnopqrstuvwxyz";

const string substitutionKey = "qwertyuiopasdfghjklzxcvbnm";


int findIndex(char c, const string& reference) {
    for (int i = 0; i < reference.length(); ++i) {
        if (reference[i] == c) {
            return i;
        }
    }
    return -1;
}


string substituteText(const string& text, bool decrypt) {
    string result = "";
    for (int i = 0; i < text.length(); ++i) {
        char c = text[i];

       
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
        text = readTextFromFile("C:\\Users\\User\\Desktop\\uni\\data structures and algorithms\\lab_18,19\\task_2\\text.txt");
        cout << "Read from file: " << text << endl;
    }
    else {
        cout << "Invalid input source.\n";
        return 1;
    }

    bool decrypt = false;
    if (mode == 2) {
        decrypt = true;
    }

    string result = substituteText(text, decrypt);

    if (decrypt == true) {
        cout << "Decrypted text:\n";
    }
    else {
        cout << "Encrypted text:\n";
    }

    cout << result << endl;

    return 0;
}
