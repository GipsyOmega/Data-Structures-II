#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        N = 0;
    }

    void push(int val)
    {
        q2.push(val);

        while (!q1.empty())
        {
            N++;
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {
        q1.pop();
        N--;
    }

    int top()
    {
        return q1.front();
    }

    int size()
    {
        return N;
    }

    void display()
    {
        while (!q1.empty())
        {
            cout << q1.front() << "\t";
            q1.pop();
        }
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << "Last Element: " << st.top() << endl;
    cout << "Display Stack" << endl;
    st.display();
    cout << endl;
    return 0;
}