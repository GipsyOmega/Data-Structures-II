#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }

    else if (c == '*' || c == '/')
    {
        return 2;
    }

    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infix2prefix(string s)
{
    reverse(s.begin(), s.end());
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            result += s[i];
        }

        else if (s[i] == ')')
        {
            st.push(s[i]);
        }

        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                result += st.top();
                st.pop();
            }

            if (!st.empty())
            {
                st.pop();
            }
        }

        else
        {
            while (!st.empty() && precedence(st.top()) > precedence(s[i]))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    cout << "Output" << endl;
    cout << "Prefix Expression " << infix2prefix("(x-y/z)+b/c") << endl;
    return 0;
}
