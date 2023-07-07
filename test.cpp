#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void initializeGraph(Node *A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        A[i] = NULL;
    }
}
Node *getNewNode(int data, Node *head)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    return newNode;
}
void addEdge(int src, int dest, Node *head[])
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
int solve(int weight[], int capacity[], int n, int maxCapacity, int **dp)
{
    if (maxCapacity == 0 || n == 0)
    {
        return 0;
    }
    if (dp[n][maxCapacity] != -1)
    {
        return dp[n][maxCapacity];
    }
    int inc = 0;
    if (capacity[n - 1] <= maxCapacity)
    {
        inc = weight[n - 1] + solve(weight, capacity, n - 1, maxCapacity - capacity[n - 1], dp);
    }
    int exc = solve(weight, capacity, n - 1, maxCapacity, dp);
    return dp[n][maxCapacity] = max(inc, exc);
}
void assign(int **dp, int n, int maxCapacity)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < maxCapacity + 1; j++)
        {
            dp[i][j] = -1;
            // cout << dp[i][j] << " " << ++c << " ";
        }
    }
}
int solve2(int weight[], int capacity[], int n, int index, int maxCapacity, int currentCapacity, int **dp)
{
    if (index >= n)
    {
        return 0;
    }
    int inc = 0;
    if (currentCapacity < maxCapacity)
    {
        inc = weight[index] + solve2(weight, capacity, n, index + 1, maxCapacity, currentCapacity + capacity[index], dp);
    }
    // if (dp[index][currentCapacity] != -1)
    // {
    //     return dp[index][currentCapacity];
    // }
    // cout << "left " << currentCapacity << endl;
    // cout << "right " << currentCapacity << endl;
    int exc = solve2(weight, capacity, n, index + 1, maxCapacity, currentCapacity, dp);
    // cout << "out " << currentCapacity << " " << max(inc, exc) << endl;
    return max(inc, exc);
}

// void solve3(int arr[], int n)
// {
//     vector<int> span(n);
//     cout << n << endl;
//     span[0] = 1;
//     stack<int> S;
//     S.push(0);
//     for (int i = 1; i < n; i++)
//     {
//         while (!S.empty() && arr[i] > arr[S.top()])
//         {
//             S.pop();
//         }
//         span[i] = S.empty() ? i + 1 : i - S.top();
//         S.push(i);
//     }
//     for (int x : span)
//     {
//         cout << x << " ";
//     }
//     cout << "END";
//     return;
// }

int main()
{

    //     {0}
    //   /  |  \
    // {1}  |   {2}
    //    \ |  /
    //     {3}
    //      |
    //     {4}

    // Number of node

    // for input format type in string

    // int N = 5;
    // Node *A[N];
    // initializeGraph(A, N);
    // addEdge(0, 1, A);
    // addEdge(0, 2, A);
    // addEdge(0, 3, A);
    // // addEdge(1, 0, A);
    // addEdge(1, 3, A);
    // // addEdge(2, 0, A);
    // addEdge(2, 3, A);
    // // addEdge(3, 0, A);
    // // addEdge(3, 1, A);
    // // addEdge(3, 2, A);
    // addEdge(3, 4, A);
    // // addEdge(4, 3, A);
    // for (int i = 0; i < N; i++)
    // {
    //     cout << i << "__";
    //     print(A[i]);
    // }
    // int n, maxCapacity;
    // cin >> n >> maxCapacity;
    // int capacity[n];
    // int weight[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> capacity[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> weight[i];
    // }
    // int **dp = new int *[n + 1];
    // for (int i = 0; i < n + 1; i++)
    // {
    //     dp[i] = new int[maxCapacity + 1];
    // }
    // assign(dp, n, maxCapacity);
    // // cout << solve(weight, capacity, n, maxCapacity, dp) << endl;
    // cout << solve2(weight, capacity, n, 0, maxCapacity, 0, dp) << endl;
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << n << endl;
    // solve3(arr, n);
    // string str;
    // getline(cin >> ws, str);
    // // cout << str;
    // vector<int> arr;
    // string num = "";
    // for (auto x : str)
    // {
    //     if (x == ' ')
    //     {
    //         stringstream inp(num);
    //         int newNum = 0;
    //         inp >> newNum;
    //         arr.push_back(newNum);
    //         num = "";
    //     }
    //     else
    //         num = num + x;
    // }
    // int max = INT_MIN;
    // int c = 0;
    // for (int x = 0; x < arr.size(); x++)
    // {
    //     if (arr[x] > max)
    //     {
    //         max = arr[x];
    //     }
    // }
    // for (auto x : arr)
    // {
    //     cout << x << endl;
    // }
    // return 0;

    // int a;
    // bool c{true};
    // // cin >> a;
    // cin >> std::boolalpha >> c;
    // cout << c;

    // if (c)
    // {
    //     cout << "true";
    // }
}