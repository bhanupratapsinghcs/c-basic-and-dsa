#include <iostream>
using namespace std;
// stack using Array

class StackUsingArray
{
public:
    int top = -1;
    int A[101];
    void push(int data)
    {
        if (top == 100)
        {
            cout << "Stack overflow";
            return;
        }
        A[++top] = data;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
        }
        top--;
    }
    int Top()
    {
        return A[top];
    }
    void print()
    {
        cout << "Stack: ";
        for (int i = 0; i <= top; i++)
        {
            cout << A[i] << " ";
        }
        cout << "\n";
    }
};

// stack using Linked list

class Stack
{
public:
    struct Node
    {
        int data;
        Node *link;
    };
    Node *top = NULL; // Here head is treated as top
    void push(int data)
    {
        Node *temp = new Node(); // creating new node to add to top/head of linked list
        temp->data = data;       // add data to new node
        temp->link = top;        // creating link and setting top as temp next node
        top = temp;              // unlinking top from head and setting temp as top
    }
    void pop()
    {
        if (top == NULL)
        {
            return;
        }
        Node *temp = top; // save top in temp node
        top = temp->link; // unlink the top from head and setting top next as top
        delete temp;      // deleting previous top as temp
    }
    int Top()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        Node *temp = top;
        cout << "Stack: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << "\n";
    }
};
int main()
{
    // StackUsingArray sa = StackUsingArray();
    Stack sa = Stack();
    cout << sa.isEmpty() << "\n";
    sa.push(2);
    sa.print();
    sa.push(3);
    sa.print();
    sa.push(4);
    sa.print();
    sa.pop();
    sa.print();
    sa.pop();
    sa.print();
    cout << sa.isEmpty() << "\n";

    cout << sa.Top() << "\n";
}