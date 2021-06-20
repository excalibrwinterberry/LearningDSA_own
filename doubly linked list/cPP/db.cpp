#include <iostream>
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

void insertAtHead(node *&head, int val)
{

    node *newNode = new node(val);

    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertAtTail(node *&head, int val)
{

    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node *newNode = new node(val);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void deleteAt(node *&head, int pos)
{
    node *temp = head;

    if (pos == 1)
    { // edge condition for first node
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    { // when position is out of bound
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL) // edge condition for last node
        temp->next->prev = temp->prev;
    delete temp;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    deleteAt(head, 7);
    display(head);

    return 0;
}