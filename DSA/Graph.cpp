#include <iostream>
using namespace std;

// Weighted Undirected Graph Implementation using Adjacency Matrix
class WeightedGraphImpUsingAdjacencyMatrix
{
    void initializeMatrix(int **Matrix)
    {
        for (int i = 0; i < N; i++)
        {
            Matrix[i] = new int[N];
        }
    }
    int N;

public:
    int **Matrix = new int *[N];
    WeightedGraphImpUsingAdjacencyMatrix(int N)
    {
        this->N = N;
        initializeMatrix(Matrix);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                Matrix[i][j] = INT_MAX;
            }
        }
    }
    void addEdge(int src, int dest, int weight)
    {
        Matrix[src][dest] = weight;
        Matrix[dest][src] = weight; // -> for undirected graph implementation
    }
    void print()
    {
        for (int i = 0; i < N; i++)
        {
            cout << i << "__";
            for (int j = 0; j < N; j++)
            {
                if (Matrix[i][j] < INT_MAX)
                {
                    cout << "->" << j << " W = " << Matrix[i][j];
                }
                // cout << Matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Unweighted Undirected Graph Implementation using Adjacency Matrix
class GraphImpUsingAdjacencyMatrix
{
    void initializeMatrix(int **Matrix)
    {
        for (int i = 0; i < N; i++)
        {
            Matrix[i] = new int[N];
        }
    }
    int N;

public:
    int **Matrix = new int *[N];
    GraphImpUsingAdjacencyMatrix(int N)
    {
        this->N = N;
        initializeMatrix(Matrix);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                Matrix[i][j] = 0;
            }
        }
    }
    void addEdge(int src, int dest)
    {
        Matrix[src][dest] = 1;
        Matrix[dest][src] = 1; // -> for undirected graph implementation
    }
    void print()
    {
        for (int i = 0; i < N; i++)
        {
            cout << i << "__";
            for (int j = 0; j < N; j++)
            {
                if (Matrix[i][j] == 1)
                {
                    cout << "->" << j;
                }
                // cout << Matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Directed UnWeighted Graph Implementation without using STL library
class DirectedGraphImpUsingAdjacencyList
{
    // Data Structure to store Adjacency list Node
    struct Node
    {
        int data;
        Node *next;
    };
    Node *getNewNode(int data, Node *head)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        return newNode;
    }
    int N;

public:
    struct Edge
    {
        int src, dest;
    };
    Node **head;
    DirectedGraphImpUsingAdjacencyList(Edge edges[], int n, int)
    {
        head = new Node *[N](); // allocating memory to an Array of pointers to Node to represent the adjancency
        this->N = N;

        // initialize head pointer for all vertices
        for (int i = 0; i < N; i++)
        {
            head[i] = NULL;
        }

        // adding edges to the directed graph
        for (int i = 0; i < n; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            Node *newNode = getNewNode(dest, head[src]);
            // // insert at the begining
            // // point head pointer to the new node
            head[src] = newNode;
            // Node *newNode2 = getNewNode(src, head[dest]); // this is for bidirection link setup and make graph undirected
            // head[dest] = newNode2;
        }
    }
    // Destructor
    ~DirectedGraphImpUsingAdjacencyList()
    {
        for (int i = 0; i < N; i++)
        {
            delete[] head[i];
        }
        delete[] head;
    }
    void print(Node *head)
    {
        while (head != nullptr)
        {
            cout << "->" << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
};

// Undirected UnWeighted Graph Implementation without using STL library
class UnDirectedGraphImpUsingAdjacencyList
{
    struct Node
    {
        int data;
        Node *next;
    };
    int N;

public:
    Node **head;
    UnDirectedGraphImpUsingAdjacencyList(int N)
    {
        this->N = N;
        this->head = new Node *[N]();
        for (int i = 0; i < N; i++)
        {
            head[i] = NULL;
        }
    }
    Node *getNewNode(int data, Node *head)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        return newNode;
    }
    void addEdge(int src, int dest)
    {
        // need only one node for directed graph
        Node *newNode = getNewNode(dest, head[src]);
        head[src] = newNode;
        // this second node is to connect bi-directional link between two node
        Node *newNode2 = getNewNode(src, head[dest]);
        head[dest] = newNode2;
        return;
    }
    void print(Node *head)
    {
        while (head != nullptr)
        {
            cout << "->" << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
    ~UnDirectedGraphImpUsingAdjacencyList()
    {
        for (int i = 0; i < N; i++)
        {
            delete[] head[i];
        }
        delete[] head;
    }
};

// Map Implementation of Graph
class GraphWithMap
{
};
int main()
{
    /*
    // pair `(x, y)` represents an edge from `x` to `y`

    DirectedGraphImpUsingAdjacencyList::Edge edges[] = {
        {0, 1}, {1, 2}, {2, 0}, {3, 2}, {4, 5}, {5, 4}, {1, 5}};
    int N = 6;
    int n = sizeof(edges) / sizeof(edges[0]);

    DirectedGraphImpUsingAdjacencyList *DG = new DirectedGraphImpUsingAdjacencyList(edges, n, N);

    for (int i = 0; i < N; i++)
    {
        cout << i << "__";
        DG->print(DG->head[i]);
    }
    */

    int N = 5;
    //     {0}
    //   /  |  \
    // {1}  |   {2}
    //    \ |  /
    //     {3}
    //      |
    //     {4}

    UnDirectedGraphImpUsingAdjacencyList *UDG = new UnDirectedGraphImpUsingAdjacencyList(N);
    // GraphImpUsingAdjacencyMatrix *UDG = new GraphImpUsingAdjacencyMatrix(N);
    // WeightedGraphImpUsingAdjacencyMatrix *UDG = new WeightedGraphImpUsingAdjacencyMatrix(N);
    UDG->addEdge(0, 1);
    UDG->addEdge(0, 2);
    UDG->addEdge(0, 3);
    UDG->addEdge(1, 3);
    UDG->addEdge(2, 3);
    UDG->addEdge(3, 4);
    // addEdge(1, 0, A);
    // addEdge(2, 0, A);
    // addEdge(3, 0, A);
    // addEdge(3, 1, A);
    // addEdge(3, 2, A);
    // addEdge(4, 3, A);
    // UDG->print();
    for (int i = 0; i < N; i++)
    {
        cout << i << "__";
        UDG->print(UDG->head[i]);
    }
}