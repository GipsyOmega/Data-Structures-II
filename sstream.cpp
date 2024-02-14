#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    stringstream ss;
    stringstream st;
    ss << "2.54.66";
    st << "1.1.11";
    string s;
    int a, b = 0;
    ss >> b;
    st >> a;
    float c = (float)2 / (float)4;

    cout << c << endl;
    cout << b << " " << a;
}