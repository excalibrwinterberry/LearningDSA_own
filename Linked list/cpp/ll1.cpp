#include <iostream>
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

void insertAtTail(node *&head, int val)
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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void display(node *head)
{

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

bool searchList(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

void deletion(node *&head, int val)
{
    if (head == NULL) // if the linked list is empty
        return;

    if (searchList(head, val))
    {
        node *temp = head;
        if (head->data == val) //if the node to be deleted is the first node
        {
            head = head->next;
            delete temp;
            return;
        }
        while (temp->next->data != val)
        {
            temp = temp->next;
        }
        node *toDelete = temp->next;
        temp->next = temp->next->next;

        delete toDelete;
    }
}

void deleteAtTail(node *&head)
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    node *toDelete = temp->next;
    temp->next = NULL;
    delete toDelete;
}

void deleteAtHead(node *&head)
{
    node *temp = head;
    head = head->next;
    delete temp;
}

node *reverseItr(node *&head)
{

    node *prevptr = NULL;
    node *currrptr = head;
    node *nextptr;

    while (currrptr != NULL)
    {
        nextptr = currrptr->next;
        currrptr->next = prevptr;

        prevptr = currrptr;
        currrptr = nextptr;
    }

    return prevptr;
}

node *reverseRecur(node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newHead = reverseRecur(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

node *reversek(node *&head, int k)
{

    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    int count = 0;

    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if (nextptr != NULL)
    {
        head->next = reversek(nextptr, k);
    }

    return prevptr;
}

bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

//  void makeCycle(node *head, int pos){
//     node *temp = head;
//     node *startNode;
//     int count = 1;
//     while (temp != NULL)
//     {
//         if (count == pos)
//         {
//             startNode = temp;
//         }
//         temp = temp->next;
//         count++;
//     }
//     temp->next = startNode;
// }

int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

void appendLastNodesToStart(node *&head, int pos)
{
    if (pos >= length(head))
        return;
    node *newTail = head;
    int count = 1;
    while (newTail != NULL && count != pos)
    {
        newTail = newTail->next;
        count++;
    }
    node *temp = newTail;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head = newTail->next;
    newTail->next = NULL;
}

node *kappend(node *head, int k)
{
    node *newHead;
    node *newTail;
    node *tail = head;

    int l = length(head);
    k = k % l; // to lower k if k>l
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newTail = tail;
        }
        if (count == l - k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

void removeCycle(node *head)
{
    node *slow = head;
    node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

void findIntersect(node *head1, node *head2)
{
    int l1 = length(head1);
    node *arr[l1];
    node *temp = head1;
    int i = 0;
    while (temp != NULL)
    {
        arr[i++] = temp;
        temp = temp->next;
    }
    temp = head2;
    i = 0;
    while (temp != NULL)
    {
        if (arr[i] == temp)
        {
            cout << temp->data;
            return;
        }
        temp = temp->next;
        i++;
    }
    cout << -1;
}

int intersection(node *&head1, node *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;

    node *ptr1; // bigger ll
    node *ptr2;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    // reaching the eqidistant node from intersection
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {

        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

void intersect(node *&head1, node *head2, int pos)
{
    node *temp1 = head1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }

    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

node *merge(node *&head1, node *&head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *dummyNode = new node(-1); // to store the address of merged ll as its next
    node *ptr3 = dummyNode;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    //when any of the ll is not traversed fully
    while (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return dummyNode->next; //new head of the merged ll;
}

node *mergeRecur(node *&head1, node *&head2)
{

    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecur(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecur(head1, head2->next);
    }

    return result;
}

int main()
{

    node *head = NULL;
    node *head1 = NULL;
    node *head2 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);
    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 6);
    display(head1);
    display(head2);
    node *newHead = mergeRecur(head1, head2);
    display(newHead);
    return 0;
}
