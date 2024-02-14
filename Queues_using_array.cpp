#include <iostream>
#define stacksize = 100
using namespace std;
int queue[100], n = 100, front = -1, rear = -1;

void enqueue(int val)
{
    if (rear == n - 1)
    {
        cout << "Queue Stackflow\n";
    }
    else
    {
        if (front == -1)
        {
            front++;
        }
        rear++;
        queue[rear] = val;
    }
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Stack Overflow\n";
    }
    else
    {
        int d = queue[front];
        front++;
        if (front > rear)
        {
            front = -1, rear = -1;
        }
    }
}
void display()
{
    if (rear == -1)
        cout << "Queue Empty\n";
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << '\t';
    }
    cout << endl;
}
int main()
{
    int ch, val;
    cout << "1) Enqueue" << endl;
    cout << "2) Dequeue" << endl;
    cout << "3) Display Queue" << endl;
    cout << "4) Exit" << endl;
    do
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            enqueue(val);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 4);
    return 0;
}