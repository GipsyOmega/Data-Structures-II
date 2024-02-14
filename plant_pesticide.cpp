#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

using namespace std;

int poisonousPlants(vector<int> p)
{
    stack<pair<int, int> > plants;
    int days = 0;
    for (int i = p.size() - 1; i >= 0; i--)
    {
        int temp = 0;
        while (!plants.empty() && plants.top().first > p[i])
        {
            if (plants.top().second > temp)
                temp = plants.top().second;
            else
                temp++;
            plants.pop();
        }
        days = max(days, temp);
        plants.push(make_pair(p[i], temp));
    }
    return days;
}
// 7 6 5 8 4 7 10 9
int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        int p_item;
        cin >> p_item;
        p[i] = p_item;
    }
    int result = poisonousPlants(p);
    cout << "Result: " << result << endl;
    return 0;
}