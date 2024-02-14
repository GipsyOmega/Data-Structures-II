#include <iostream>
using namespace std;
int N = 100, cnt;

struct stack
{
    int top = -1;
    int del;
    int arr[100];

    void push(int val)
    {
        if (top >= N - 1)
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    int pop()
    {
        if (top <= -1)
            cout << "Stack Underflow" << endl;
        else
        {
            del = arr[top];
            //cout << "The popped element is " << del << endl;
            top--;
        }
        return del;
    }
};

stack s1, s2;

void enqueue(int val)
{
    s1.push(val);
    cnt++;
}

void dequeue()
{
    if ((s1.top == -1) && (s2.top == -1))
    {
        cout << "Queue is empty\n";
    }
    else
    {
        for (int i = 0; i < cnt; i++)
        {
            int element = s1.pop();
            s2.push(element);
        }
        int b = s2.pop();
        //cout << "The dequeued element is " << b << endl;
        printf("\n");

        cnt--;
        for (int i = 0; i < cnt; i++)
        {
            int a = s2.pop();
            s1.push(a);
        }
    }
}

void display()
{
    for (int i = 0; i <= s1.top; i++)
    {
        cout << s1.arr[i] << "\t";
    }
    cout << endl;
}

int main()
{
    enqueue(3);
    enqueue(2);
    enqueue(5);
    dequeue();
    enqueue(1);
    enqueue(9);
    dequeue();
    enqueue(2);
    enqueue(7);
    display();
    return 0;
}