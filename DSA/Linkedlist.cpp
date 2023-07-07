#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
// here we decalare the head as global variable so it is initialise only ones
// we can also initialise head in main function but then we have to pass head referance to each function
Node *head;

// Inserting in a linkedlist

void InsertinBeginning(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}
void InsertAtNthNode(int data, int n)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    // special case when adding at first node
    if (n == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    // adding add at nth node
    Node *temp2 = head;
    for (int i = 0; i < n - 2; i++) // loop till n-1 node
    {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
}
void InsertAtEnd(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    // special case when head is NULL
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    // set temp2.next to temp only
    temp2->next = temp;
}

// Deleting node from a linkedlist

void deletingFromBeginning()
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    head = head->next;

    delete temp;
}

void deleteAtNth(int index)
{
    Node *temp = head;
    if (index == 1)
    {
        head = temp->next;
        delete temp;
        return;
    }
    for (int i = 0; i < index - 2; i++)
    {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}

void deleteFromEnd()
{
    // Node *second_node;
    // second_node = head;
    // if (head == NULL)
    // {
    //     return;
    // }
    // if (head->next == NULL)
    // {
    //     delete head;
    //     return;
    // }
    // while (second_node->next->next != NULL)
    // {
    //     second_node = second_node->next;
    // }
    // delete second_node;
    // second_node->next = NULL;

    // second approch

    Node *current, *prev;
    current = head;
    prev = NULL;
    if (current == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        delete current;
        return;
    }
    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    delete current;
    prev->next = NULL;
}
void deleteWithKey(int key)
{
    Node *current, *prev;
    current = head;
    prev = NULL;
    if (current == NULL)
    {
        return;
    }
    // special case check whether the key is in head node or not
    if (current != NULL && head->data == key)
    {
        head = current->next;
        delete current;
        return;
    }
    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        return;
    }
    prev->next = current->next;
    delete current;
}

// Reverse a linkedlist using iteration

void reverseItr()
{
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Reverse a linkedlist using recurrsion

void reverseRec(Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    reverseRec(p->next);
    Node *temp = p->next;
    temp->next = p;
    p->next = NULL;
}

// Reverse using stack

void ReverseUsingStack()
{
    stack<Node *> S;
    if (head == NULL)
        return;
    Node *temp = head;
    while (temp != NULL)
    {
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while (!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

// print functions

void reversePrint(Node *p)
{
    if (p == NULL)
    {
        cout << '\n';
        return;
    }
    reversePrint(p->next);
    cout << p->data << " ";
}
Node *ReversedLinkedListHalves(Node *p)
{
    Node *current, *prev, *next, *temp;
    current = temp = head;
    prev = NULL;
    if (current->next == NULL)
    {
        return current;
    }
    if (current->next->next == NULL)
    {
        return current;
    }
    int n = 0;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    int mid = n / 2;
    int i = 1;
    while (current != NULL)
    {
        if (i++ <= mid)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        else
        {
        }
    }
    head = prev;
    cout << n << endl;
    return p;
}

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
int main()
{
    head = NULL;
    InsertinBeginning(3);  // 3
    InsertinBeginning(4);  // 4 3
    InsertinBeginning(6);  // 6 4 3
    InsertinBeginning(9);  // 9 6 4 3
    InsertAtNthNode(9, 4); // 9 6 4 9 3
    InsertAtNthNode(1, 2); // 9 1 6 4 9 3
    InsertAtNthNode(7, 3); // 9 1 7 6 4 9 3
    InsertAtNthNode(0, 1); // 0 9 1 7 6 4 9 3
    InsertAtEnd(5);        // 0 9 1 7 6 4 9 3 5
    InsertAtEnd(10);       // 0 9 1 7 6 4 9 3 5 10
    // deletingFromBeginning(); // 9 1 7 6 4 9 3 5 10
    // deletingFromBeginning(); // 1 7 6 4 9 3 5 10
    // deleteAtNth(3);          // 1 7 4 9 3 5 10
    // deleteAtNth(1);          // 7 4 9 3 5 10
    // deleteAtNth(6);          // 7 4 9 3 5
    // reverseItr();            // 5 3 9 4 7
    // reverseRec(head);        // 7 4 9 3 5
    // deleteFromEnd();         // 7 4 9 3
    // deleteWithKey(7);        // 4 9 3
    // ReverseUsingStack();
    ReversedLinkedListHalves(head);
    print();
    // reversePrint(head); // it only print in reverse order
}