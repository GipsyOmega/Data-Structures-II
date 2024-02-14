#include <iostream>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertatHead(node *&head, int val)
{
    node *newnode = new node(val);
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
}

void insertatTail(node *&head, int val)
{
    node *newnode = new node(val);
    if (head == NULL)
    {
        insertatHead(head, val);
        return;
    }
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertatTail(head, 3);
    insertatTail(head, 1);
    insertatTail(head, 5);
    insertatTail(head, 7);
    display(head);
    insertatHead(head, 2);
    display(head);
}