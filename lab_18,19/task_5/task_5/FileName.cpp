#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int SIZE = 5;
char matrix[SIZE][SIZE];
bool used[26];

void createMatrix(const string& keyword) 
{
    for (int i = 0; i < 26; i++) used[i] = false;
    used['J' - 'A'] = true;

    string cleanedKey = "";
    for (char c : keyword) 
    {
        c = toupper(c);
        if (c == 'J') c = 'I';
        if (c >= 'A' && c <= 'Z' && !used[c - 'A']) 
        {
            cleanedKey += c;
            used[c - 'A'] = true;
        }
    }

    for (char c = 'A'; c <= 'Z'; c++) 
    {
        if (!used[c - 'A'])
        {
            cleanedKey += c;
            used[c - 'A'] = true;
        }
    }

    int index = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = cleanedKey[index++];
}

void findPosition(char letter, int& row, int& col) 
{
    if (letter == 'J') letter = 'I';
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (matrix[i][j] == letter) 
            {
                row = i;
                col = j;
                return;
            }
}

string prepareText(const string& text)
{
    string result = "", cleaned = "";
    for (char c : text) {
        c = toupper(c);
        if (c >= 'A' && c <= 'Z') 
        {
            if (c == 'J') c = 'I';
            cleaned += c;
        }
    }

    for (int i = 0; i < cleaned.length(); i++)
    {
        char first = cleaned[i];
        char second;
        if (i + 1 < cleaned.length()) {
            second = cleaned[i + 1];
        }
        else {
            second = 'X';
        }

        if (first == second) 
        {
            result += first;
            result += 'X';
        }
        else 
        {
            result += first;
            result += second;
            i++;
        }
    }

    if (result.length() % 2 != 0) result += 'X';
    return result;
}

string processText(const string& text, bool encrypt)
{
    string result = "";
    for (int i = 0; i < text.length(); i += 2) {
        char a = text[i], b = text[i + 1];
        int r1, c1, r2, c2;
        findPosition(a, r1, c1);
        findPosition(b, r2, c2);

        if (r1 == r2) {
            if (encrypt) {
                result += matrix[r1][(c1 + 1) % SIZE];
                result += matrix[r2][(c2 + 1) % SIZE];
            }
            else {
                result += matrix[r1][(c1 + SIZE - 1) % SIZE];
                result += matrix[r2][(c2 + SIZE - 1) % SIZE];
            }
        }
        else if (c1 == c2) {
            if (encrypt) {
                result += matrix[(r1 + 1) % SIZE][c1];
                result += matrix[(r2 + 1) % SIZE][c2];
            }
            else {
                result += matrix[(r1 + SIZE - 1) % SIZE][c1];
                result += matrix[(r2 + SIZE - 1) % SIZE][c2];
            }
        }
        else {
            result += matrix[r1][c2];
            result += matrix[r2][c1];
        }
    }
    return result;
}

void printMatrix() {
    cout << "Playfair Matrix:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
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
    string keyword, text;
    int choice, mode;

    cout << "Playfair Cipher\n";
    cout << "Enter keyword: ";
    getline(cin, keyword);

    createMatrix(keyword);
    printMatrix();

    cout << "1. Encrypt\n2. Decrypt\nChoose: ";
    cin >> choice;
    cin.ignore();

    cout << "Input source:\n1. Manual\n2. File (text.txt)\nChoose: ";
    cin >> mode;
    cin.ignore();

    if (mode == 1) {
        cout << "Enter text: ";
        getline(cin, text);
    }
    else if (mode == 2) {
        text = readTextFromFile("C:\\Users\\User\\Desktop\\uni\\data structures and algorithms\\lab_18,19\\task_5\\text.txt");
        cout << "Read from file: " << text << endl;
    }
    else {
        cout << "Invalid input source.\n";
        return 1;
    }

    string prepared = prepareText(text);
    string result;

    if (choice == 1) {
        result = processText(prepared, true);
        cout << "Encrypted text: " << result << endl;
    }
    else if (choice == 2) {
        result = processText(prepared, false);
        cout << "Decrypted text: " << result << endl;
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
