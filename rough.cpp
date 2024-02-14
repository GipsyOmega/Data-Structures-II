#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
using namespace std;

int main()
{
    vector<vector<int> > nums{
        {1, 2, 3, 4},
        {5, 6, 7, 8}};
    cout << nums.size();
}