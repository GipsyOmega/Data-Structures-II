// CPP program to illustrate substr()
#include <string>
#include <iostream>
#include <vector>
using namespace std;
/*
SOLVED USING DYNAMIC PROGRAMMING
*/
int SumofallSubstrings(string s)
{
    int sum = (int)s[0] - '0';
    vector<int> ans;
    ans.push_back(sum);
    for (int i = 1; i < s.length(); i++)
    {
        ans[i] = (i + 1) * (s[i] - '0') + 10 * ans[i - 1];
        sum += ans[i];
    }
    return sum;
}
int main()
{
    // Take any string
    string s = "1234";

    cout << "Original String: " << s << endl;

    vector<string> strs = {"2", "5", "12", "123", "1234", "19"};
    sort(strs.begin(), strs.end());
    for (int k = 0; k < strs.size(); k++)
    {
        cout << strs[k] << '\t';
    }
    cout << endl;
    // Find position of ':' using find()
    int pos = s.find("a");

    // Copy substring before pos
    string sub = s.substr(pos + 1);

    // prints the result
    cout << "String is: "
         << sub << endl;

    // Printing all the substrings of a string
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 1; j <= s.length() - i; j++)
        {
            cout << s.substr(i, j) << "\t";
        }
    }

    cout << SumofallSubstrings("1234") << endl;
    return 0;
}
