#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool areBracketsBalanced(string input)
{
    stack<char> st;
    for (char i : input) {
        if (i == '{' || i == '[' || i == '(')
            st.push(i);
        else if (i == '}' || i == ']' || i == ')')
        {
            if (st.empty()) return false;
            if ((i == '}' && st.top() != '{') ||
                (i == ']' && st.top() != '[') ||
                (i == ')' && st.top() != '('))
            {
                cout << "Discrepancy: " << st.top() << " and " << i << endl;
                return false;
            }
            else st.pop();
        }


    }

    if (!st.empty())
    {
        cout << "There are some unbalanced brackets.\n";
        return false;
    }

    return true;
}

int main() {

    string input = "{[()]}";

    if (areBracketsBalanced(input) == true)
        cout << "Brackets are balanced.\n";
    else
        cout << "Brackets aren't balanced.\n";


    return 0;
}
