#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> Tree;
    int noOfEdges, n1, n2;
    cin >> noOfEdges;
    Tree.resize(noOfEdges);

    for (int i = 0; i < noOfEdges; i++)
    {
        cin >> n1 >> n2;
        Tree[n1].push_back(n2);
    }
    for (const auto &e1 : Tree)
    {
        for (const auto &e2 : e1)
        {
            cout << e2 << " ";
        }
        cout << endl;
    }
}