#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    cout << "Array : " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << '\t';
    }
    cout << endl;

    cout << "Size: " << v.size() << endl;
    vector<int>::iterator it;
    for (it = v.begin(); it < v.end(); it++)
    {
        cout << *it << " ";
    }

    // for (auto element : v)
    // {
    //     cout << element << "\t";
    // }

    vector<int> v1(5, 5);
    swap(v, v1);
    for (it = v1.begin(); it < v1.end(); it++)
    {
        cout << *it << " ";
    }

    // {
    //     cout << element << "\t";
    // }
    // for (auto element : v1)
    // {
    //     cout << element << "\t";
    // }

    cout << endl;
    cout << "Size " << v.size() << endl;
    cout << "Max Size " << v.max_size() << endl;
    cout << "Capacity " << v.capacity() << endl;

    if (v1.empty() == false)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";
    cout << endl;

    v.shrink_to_fit();

    for (it = v.begin(); it < v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    // Element Access
    cout << endl;
    vector<int> g1;

    for (int i = 1; i <= 10; i++)
        g1.push_back(i * 10);

    for (it = g1.begin(); it < g1.end(); it++)
    {
        cout << *it << " ";
    }

    cout << "\nReference operator [g] : g1[2] = " << g1[2];

    cout << "\nat : g1.at(4) = " << g1.at(4);

    cout << "\nfront() : g1.front() = " << g1.front();

    cout << "\nback() : g1.back() = " << g1.back();

    g1.insert(g1.begin() + 6, 45);
    cout << "\ng1.insert(index, value) " << g1[6] << endl;
    for (it = g1.begin(); it < g1.end(); it++)
    {
        cout << *it << " ";
    }

    g1.erase(g1.begin() + 6);
    cout << "\ng1.erase() " << g1[6] << endl;
    for (it = g1.begin(); it < g1.end(); it++)
    {
        cout << *it << " ";
    }

    g1.clear();
    cout << "\ng1.clear() " << g1.size() << endl;
    for (it = g1.begin(); it < g1.end(); it++)
    {
        cout << *it << " ";
    }

    // pointer to the first element
    int *pos = g1.data();

    cout << "\nThe first element is " << *pos;

    // cout << "2-D Vector" << endl;

    // vector<vector<int> > matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     for (int j = 0; j < matrix[i].size(); j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // return 0;
}
