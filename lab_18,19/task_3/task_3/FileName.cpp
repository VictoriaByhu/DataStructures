#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int ALPHABET_SIZE = 26;


char toLowerChar(char c) 
{
    if (c >= 'A' && c <= 'Z') 
    {
        return c + ('a' - 'A');
    }
    return c;
}


void printVigenereTable() 
{
    cout << "Vigenóre table:\n";
    for (int row = 0; row < ALPHABET_SIZE; ++row) 
    {
        for (int col = 0; col < ALPHABET_SIZE; ++col) 
        {
            char ch = 'A' + (row + col) % ALPHABET_SIZE;
            cout << ch << " ";
        }
        cout << endl;
    }
}


string extendKey(const string& text, const string& key) 
{
    string result = "";
    int j = 0;
    for (int i = 0; i < text.length(); ++i) 
    {
        char c = text[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) 
        {
            result += key[j % key.length()];
            j++;
        }
        else {
            result += ' '; 
        }
    }
    return result;
}


string vigenereEncrypt(const string& text, const string& key) 
{
    string result = "";
    for (int i = 0; i < text.length(); ++i) 
    {
        char c = text[i];
        char k = toLowerChar(key[i]);

        if (c >= 'A' && c <= 'Z') 
        {
            int offset = (c - 'A' + (k - 'a')) % ALPHABET_SIZE;
            result += 'A' + offset;
        }
        else if (c >= 'a' && c <= 'z') 
        {
            int offset = (c - 'a' + (k - 'a')) % ALPHABET_SIZE;
            result += 'a' + offset;
        }
        else 
        {
            result += c;
        }
    }
    return result;
}


string vigenereDecrypt(const string& text, const string& key)
{
    string result = "";
    for (int i = 0; i < text.length(); ++i) 
    {
        char c = text[i];
        char k = toLowerChar(key[i]);

        if (c >= 'A' && c <= 'Z')
        {
            int offset = (c - 'A' - (k - 'a') + ALPHABET_SIZE) % ALPHABET_SIZE;
            result += 'A' + offset;
        }
        else if (c >= 'a' && c <= 'z') 
        {
            int offset = (c - 'a' - (k - 'a') + ALPHABET_SIZE) % ALPHABET_SIZE;
            result += 'a' + offset;
        }
        else 
        {
            result += c;
        }
    }
    return result;
}

int main() 
{
    int mode;
    cout << "1 - Encrypt\n2 - Decrypt\nChoose: ";
    cin >> mode;

    string text, key;
    cout << "Enter text: ";
    cin.ignore();
    getline(cin, text);

    cout << "Enter keyword: ";
    getline(cin, key);

    string extendedKey = extendKey(text, key);
    string result;

    if (mode == 1) 
    {
        result = vigenereEncrypt(text, extendedKey);
        cout << "Encrypted text:\n" << result << endl;
    }
    else if (mode == 2) 
    {
        result = vigenereDecrypt(text, extendedKey);
        cout << "Decrypted text:\n" << result << endl;
    }
    else 
    {
        cout << "Wrong input." << endl;
        return 1;
    }

    cout << "\nShow table? (1 - yes, 0 - no): ";
    int showTable;
    cin >> showTable;

    if (showTable == 1) 
    {
        printVigenereTable();
    }

    return 0;
}
