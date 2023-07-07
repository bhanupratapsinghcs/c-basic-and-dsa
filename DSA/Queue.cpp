#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 101
// implementing Queue using circular array
class QueueUsingArray
{
private:
    int A[MAX_SIZE];
    int front, rear;

public:
    QueueUsingArray()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }
    bool isFull()
    {
        return (rear + 1) % MAX_SIZE == front ? true : false; // important rear should be increased by 1 to get proper index of rear
    }
    void Enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE; // it will in increase the rear by 1
        }
        A[rear] = data;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "stack is empty\n";
        }
        else if (rear == front)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE; // it will decrease the size of front and dequeue the queue
        }
    }
    int Front()
    {
        if (front == -1)
        {
            cout << "stack is empty\n";
            return -1;
        }
        return A[front];
    }
    int size()
    {
        // cout << "rear :" << rear << " front: " << front << "\n";
        return (rear + MAX_SIZE - front) % MAX_SIZE + 1;
    }
    void print()
    {
        int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1; // finding the size of array or number of element in Queue
        cout << "count : " << count << " Queue: ";
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % MAX_SIZE;
            cout << A[index] << " ";
        }
        cout << "\n";
    }
};

// implementing Queue using linked list

class Queue
{
    struct Node
    {
        int data;
        Node *next;
    };

public:
    Node *front = NULL;
    Node *rear = NULL;
    bool isEmpty() // checking by front and rear as null returning the condition
    {
        return (front == NULL && rear == NULL) ? true : false;
    }
    void Enqueue(int data)
    {
        Node *temp = new Node(); // creating a new node
        temp->data = data;       // adding data to node
        temp->next = NULL;       // refering temp next node as NULL
        if (isEmpty())           // special case when queue is empty
        {
            front = rear = temp; // refering front and rear as temp
            return;
        }
        rear->next = temp; // refering rear next node as temp
        rear = temp;       // setting temp as rear
    }
    void Dequeue()
    {
        Node *temp = front; // creating a temperory Node as front
        if (front == NULL)  // special case when Queue is empty
        {
            cout << "Queue is empty already";
            return;
        }
        else if (front == rear)  // special condtition when front and rear are equal or
        {                        // front become rear after deleting all element
            front = rear = NULL; // set front and rear as null
        }
        else
        {
            front = front->next; // main condition when deleting from the front set
        }                        // set front as front next and unlink the front from queue
        delete temp;             // deleting front unlinked from the queue
    }
    int Front() // sending the data of front node
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }
        return front->data;
    }
    int size() // counting by iterating till front is null and returning count
    {
        int count = 0;
        if (isEmpty()) // special case if queue is empty
        {
            return count;
        }
        Node *temp = front;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    void print()
    {
        Node *temp = front;
        cout << "Queue : ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    // QueueUsingArray Q;// for Queue using circular array
    Queue Q;
    cout << "Empty: " << Q.isEmpty() << '\n';
    cout << "front: " << Q.Front() << "\n";
    Q.Enqueue(2);
    Q.print();
    Q.Enqueue(5);
    Q.print();
    Q.Enqueue(6);
    Q.print();
    Q.Enqueue(3);
    Q.print();
    cout << "size: " << Q.size() << "\n";
    Q.Enqueue(4);
    Q.print();
    Q.Enqueue(9);
    Q.print();
    cout << "size: " << Q.size() << "\n";
    Q.Dequeue();
    Q.print();
    cout << "front: " << Q.Front() << "\n";
    // cout << "full: " << Q.isFull() << '\n';
}