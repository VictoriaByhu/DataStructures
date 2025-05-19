#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>
using namespace std;

// ������� ����������/������������ ������
string caesarCipher(const string& text, int shift, bool decrypt = false) {
    string result = "";
    if (decrypt) shift = -shift;

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + shift + 26) % 26 + base;
        }
        result += c;
    }
    return result;
}

// ��������� �����
int frequencyDecrypt(const string& cipherText) {
    map<char, int> freq;
    for (char c : cipherText) {
        if (isalpha(c)) freq[tolower(c)]++;
    }

    // ��������� ������� ����� � ���� ��� � 'e'
    char mostFrequent = max_element(freq.begin(), freq.end(),
        [](auto& a, auto& b) { return a.second < b.second; })->first;

    int shift = (mostFrequent - 'e' + 26) % 26;
    return shift;
}

string readText(bool fromFile) {
    string text;
    if (fromFile) {
        string filename;
        cout << "������ ��'� �����: ";
        cin >> filename;
        ifstream inFile(filename);
        if (inFile) {
            getline(inFile, text, '\0');
            inFile.close();
        }
        else {
            cout << "�� ������� ������� ����.\n";
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
    cout << "1 - ����������\n2 - ������������ (����)\n3 - ������������ (��������� �����)\n��� ����: ";
    cin >> mode;

    bool fromFile;
    cout << "������� ����� � �����? (1 - ���, 0 - �): ";
    cin >> fromFile;
    string text = readText(fromFile);

    if (mode == 1) {
        int shift;
        cout << "������ ���� ����� (���� ���� �䒺����): ";
        cin >> shift;
        cout << "������������ �����: " << caesarCipher(text, shift) << endl;
    }
    else if (mode == 2) {
        int shift;
        cout << "������ ���� ����� ��� ������������: ";
        cin >> shift;
        cout << "������������ �����: " << caesarCipher(text, shift, true) << endl;
    }
    else if (mode == 3) {
        int shift = frequencyDecrypt(text);
        cout << "��������� ����: " << shift << endl;
        cout << "������������ �����: " << caesarCipher(text, shift, true) << endl;
    }
    else {
        cout << "������� �����.\n";
    }

    return 0;
}
