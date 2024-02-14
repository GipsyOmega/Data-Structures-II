#include <iostream>
#include <vector>
#include <set>

using namespace std;
int main()
{
    set<int> count;
    count.insert(3);
    count.insert(4);
    count.insert(2);
    count.insert(3);
    count.insert(2);

    set<int>::iterator it;
    for (it = count.begin(); it != count.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    count.erase(2);
    count.erase(5);
    for (it = count.begin(); it != count.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}