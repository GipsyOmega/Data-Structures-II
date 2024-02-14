#include <iostream>
#include <vector>
using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.second;
}
int main()
{
    pair<int, int> p1;
    // pair p (1,2) or (3,'s')
    // p = {2,3}
    p1.first = 3;
    p1.second = 4;
    cout << p1.first << " " << p1.second << endl;

    int arr[] = {10, 7, 16, 14, 5, 3, 2, 9};
    vector<pair<int, int> > v;
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < 8; i++)
    {
        v.push_back(make_pair(arr[i], i));
    }
    cout << endl;
    sort(v.begin(), v.end(), myCompare);
    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i].second] = i;
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << arr[i] << " ";
    }
}