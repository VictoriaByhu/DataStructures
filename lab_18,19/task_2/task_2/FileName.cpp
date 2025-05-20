#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ��������� ������
const string alphabet = "abcdefghijklmnopqrstuvwxyz";

// ���� ��� ����� (�� ���� 򳺿 � �������!)
const string substitutionKey = "qwertyuiopasdfghjklzxcvbnm";

// ������� ��� ������ ������� ������� � ������
int findIndex(char c, const string& reference) {
    for (int i = 0; i < reference.length(); ++i) {
        if (reference[i] == c) {
            return i;
        }
    }
    return -1; // �� ��������
}

// ���������� ��� ������������
string substituteText(const string& text, bool decrypt) {
    string result = "";
    for (int i = 0; i < text.length(); ++i) {
        char c = text[i];

        // ���������� � ����� ������
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

// ���������� ������
string readText(bool fromFile) {
    string text;
    if (fromFile) {
        string filename;
        cout << "������ ����� �����: ";
        cin >> filename;
        ifstream inFile(filename);
        if (inFile) {
            getline(inFile, text, '\0');
            inFile.close();
        }
        else {
            cout << "�� ������� ������� ����." << endl;
        }
    }
    else {
        cout << "������ �����: ";
        cin.ignore();
        getline(cin, text);
    }
    return text;
}

int main() {
    int mode;
    cout << "1 - ����������\n2 - ������������\n��� ����: ";
    cin >> mode;

    bool fromFile;
    cout << "������� ����� � �����? (1 - ���, 0 - �): ";
    cin >> fromFile;

    string text = readText(fromFile);
    bool decrypt = false;
    if (mode == 2) {
        decrypt = true;
    }

    string result = substituteText(text, decrypt);

    if (decrypt == true) {
        cout << "������������� �����:\n";
    }
    else {
        cout << "������������ �����:\n";
    }

    cout << result << endl;

    return 0;
}
