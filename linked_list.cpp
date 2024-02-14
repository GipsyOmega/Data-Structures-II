#include <iostream>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertatHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void insertatTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
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

bool search(node *head, int key)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteatHead(node *&head)
{
    node *del = head;
    head = head->next;
    delete del;
}

node *reverse(node *&head)
{
    node *prev = NULL;
    node *current = head;
    node *nextptr;

    while (current != NULL)
    {
        nextptr = current->next;
        current->next = prev;

        prev = current;
        current = nextptr;
    }
    return prev;
}
node *reverseRec(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *n = reverseRec(head->next);
    head->next->next = head;
    head->next = NULL;

    return n;
}
void deletion(node *&head, int val)
{
    node *temp = head;

    if (head == NULL)
    {
        return;
    }

    if (temp->next == NULL)
    {
        deleteatHead(head);
        return;
    }

    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *del = temp->next;
    temp->next = temp->next->next;
    delete temp->next;
}

node *reversek(node *&head, int k)
{
    node *prevptr = NULL;
    node *current = head;
    node *nextptr;

    int count = 0;
    while (current != NULL && count < k)
    {
        nextptr = current->next;
        current->next = prevptr;
        prevptr = current;
        current = nextptr;
        count++;
    }

    if (nextptr != NULL)
    {
        head->next = reversek(nextptr, k);
    }

    return prevptr;
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
    insertatHead(head, 6);
    display(head);
    node *prev = reversek(head, 2);
    display(prev);
}