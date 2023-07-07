#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *getNewNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node *insert(Node *root)
{
    if (root == NULL)
    {
        int data;
        cin >> data;
        root = getNewNode(data);
        return insert(root);
    }
    bool hasLeftChild, hasRightChild;
    cin >> std::boolalpha >> hasLeftChild;
    if (hasLeftChild)
    {
        root->left = insert(root->left);
    }
    cin >> std::boolalpha >> hasRightChild;
    if (hasRightChild)
    {
        root->right = insert(root->right);
    }
    return root;
}
void rootOfLeaf(Node *root, vector<vector<int>> &arr, int k, vector<int> currPath)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL && k - root->data == 0)
    {
        currPath.push_back(root->data);
        arr.push_back(currPath);
        currPath.pop_back();
        return;
    }
    currPath.push_back(root->data);
    rootOfLeaf(root->left, arr, k - root->data, currPath);
    rootOfLeaf(root->right, arr, k - root->data, currPath);
    currPath.pop_back();
}
void display(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        cout << root->left->data;
    }
    else
    {
        cout << "END";
    }
    cout << " => " << root->data << " <= ";
    if (root->right != NULL)
    {
        cout << root->right->data << endl;
    }
    else
    {
        cout << "END" << endl;
    }
    display(root->left);
    display(root->right);
}
int main()
{
    Node *root = insert(NULL);
    int k;
    cin >> k;
    // cout << k << endl;
    vector<vector<int>> arr;
    vector<int> currPath;
    rootOfLeaf(root, arr, k, currPath);
    // Sample Test Case
    // 10 true 20 true 30 false false true 50 false false true 40 true 60 false false true 73 false false
    // 60

    for (auto x : arr)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}