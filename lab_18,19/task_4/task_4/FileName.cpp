#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int SIZE = 5;
char polybiusSquare[SIZE][SIZE];

void generatePolybiusSquare() 
{
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int index = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            polybiusSquare[i][j] = alphabet[index++];
}

void findCoordinates(char letter, int& row, int& col) 
{
    if (letter == 'J') letter = 'I';
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (polybiusSquare[i][j] == letter)
            {
                row = i;
                col = j;
                return;
            }
}

string encryptPolybius(const string& text)
{
    string result = "";
    for (char ch : text) 
    {
        ch = toupper(ch);
        if (ch >= 'A' && ch <= 'Z')
        {
            int row, col;
            findCoordinates(ch, row, col);
            result += to_string(row + 1);
            result += to_string(col + 1);
            result += " ";
        }
    }
    return result;
}

string decryptPolybius(const string& code) 
{
    string result = "";
    for (int i = 0; i < code.length(); i += 3) 
    {
        if (i + 1 < code.length() && isdigit(code[i]) && isdigit(code[i + 1])) 
        {
            int row = code[i] - '0' - 1;
            int col = code[i + 1] - '0' - 1;
            if (row >= 0 && row < SIZE && col >= 0 && col < SIZE)
                result += polybiusSquare[row][col];
        }
    }
    return result;
}

string readTextFromFile(const string& filename) 
{
    ifstream file(filename);
    string line, result;
    while (getline(file, line))
    {
        result += line + " ";
    }
    return result;
}

int main() 
{
    generatePolybiusSquare();

    string text;
    int mode, choice;

    cout << "Polybius Square Cipher\n";
    cout << "1. Encrypt\n2. Decrypt\nChoose: ";
    cin >> choice;
    cin.ignore();

    cout << "Input source:\n1. Manual\n2. File (input.txt)\nChoose: ";
    cin >> mode;
    cin.ignore();

    if (mode == 1) 
    {
        cout << "Enter text: ";
        getline(cin, text);
    }
    else if (mode == 2)
    {
        text = readTextFromFile("C:\\Users\\User\\Desktop\\uni\\data structures and algorithms\\lab_18,19\\task_4\\text.txt");
        cout << "Read from file: " << text << endl;
    }
    else
    {
        cout << "Invalid input source.\n";
        return 1;
    }

    if (choice == 1) 
    {
        string encrypted = encryptPolybius(text);
        cout << "Encrypted text: " << encrypted << endl;
    }
    else if (choice == 2) 
    {
        string decrypted = decryptPolybius(text);
        cout << "Decrypted text: " << decrypted << endl;
    }
    else
    {
        cout << "Invalid operation.\n";
    }

    return 0;
}
