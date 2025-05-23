#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>


using namespace std;

const string letters[36] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    "U", "V", "W", "X", "Y", "Z",
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
};

const string morse[36] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

string toUpperString(const string& input) {
    string result = "";
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            c = c - ('a' - 'A');
        }
        result += c;
    }
    return result;
}

string readFromFile(const string& filename) {
    ifstream file(filename);
    string line, result;
    while (getline(file, line)) {
        result += line + " ";
    }
    file.close();
    return result;
}

void writeToFile(const string& filename, const string& content) {
    ofstream file(filename);
    file << content;
    file.close();
}

string encryptToMorse(const string& text) {
    string result = "";
    string upper = toUpperString(text);

    for (int i = 0; i < upper.length(); i++) {
        char c = upper[i];
        if (c == ' ') {
            result += "/ ";
        }
        else {
            for (int j = 0; j < 36; j++) {
                if (letters[j][0] == c) {
                    result += morse[j] + " ";
                    break;
                }
            }
        }
    }
    return result;
}

string decryptFromMorse(const string& code) {
    string result = "";
    string symbol = "";

    for (int i = 0; i <= code.length(); i++) {
        char c;
        if (i < code.length()) {
            c = code[i];
        }
        else {
            c = ' '; // кінець рядка
        }

        if (c != ' ' && c != '/') {
            symbol += c;
        }
        else {
            if (symbol != "") {
                for (int j = 0; j < 36; j++) {
                    if (morse[j] == symbol) {
                        result += letters[j];
                        break;
                    }
                }
                symbol = "";
            }

            if (c == '/') {
                result += ' ';
            }
        }
    }

    return result;
}


void playMorseSound(const string& code) {
    for (int i = 0; i < code.length(); i++) {
        char c = code[i];
        if (c == '.') {
            Beep(800, 150); // короткий
        }
        else if (c == '-') {
            Beep(800, 400); // довгий
        }
        else if (c == ' ') {
            Sleep(100); // пауза між символами
        }
        else if (c == '/') {
            Sleep(400); // пауза між словами
        }
        Sleep(50); // невелика пауза між елементами
    }
}


int main() {
    int choice, mode;
    string text, result;

    cout << "Morse Code Program\n";
    cout << "1. Encrypt to Morse\n2. Decrypt from Morse\nChoose: ";
    cin >> choice;
    cin.ignore();

    cout << "Input source:\n1. Manual\n2. File (text.txt)\nChoose: ";
    cin >> mode;
    cin.ignore();

    if (mode == 1) {
        cout << "Enter text:\n";
        getline(cin, text);
    }
    else if (mode == 2) {
        text = readFromFile("C:\\Users\\User\\Desktop\\uni\\data structures and algorithms\\lab_18,19\\task_6\\text.txt");
        cout << "Read from file: " << text << endl;
    }
    else {
        cout << "Invalid input mode.\n";
        return 1;
    }

    if (choice == 1) {
        result = encryptToMorse(text);
        cout << "Encrypted (Morse):\n" << result << endl;
        writeToFile("C:\\Users\\User\\Desktop\\uni\\data structures and algorithms\\lab_18,19\\task_6\\output.txt", result);
        cout << "Playing Morse code...\n";
        playMorseSound(result);

    }
    else if (choice == 2) {
        result = decryptFromMorse(text);
        cout << "Decrypted (Text):\n" << result << endl;
        writeToFile("C:\\Users\\User\\Desktop\\uni\\data structures and algorithms\\lab_18,19\\task_6\\output.txt", result);
    }
    else {
        cout << "Invalid operation.\n";
        return 1;
    }

    cout << "Result written to output.txt\n";
    return 0;
}
