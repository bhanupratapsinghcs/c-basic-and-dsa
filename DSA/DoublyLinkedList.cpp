#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};
Node *head;
class DoublyLinkedlist
{
public:
    Node *GetNewNode(int data)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    }
    void InsertAtHead(int data)
    {
        // Node *temp = new Node();
        // temp->data = data;
        // temp->next = NULL;
        // temp->prev = NULL;
        Node *temp = GetNewNode(data);
        if (head == NULL)
        {
            head = temp;
            return;
        }
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    void DeleteFromHead()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << '\n';
    }
    void ReversePrint()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << '\n';
    }
};
int main()
{
    head = NULL;
    DoublyLinkedlist dll = DoublyLinkedlist();
    dll.InsertAtHead(1);
    dll.InsertAtHead(2);
    dll.InsertAtHead(3);
    dll.DeleteFromHead();
    dll.DeleteFromHead();
    dll.DeleteFromHead();
    dll.print();
    dll.ReversePrint();
}