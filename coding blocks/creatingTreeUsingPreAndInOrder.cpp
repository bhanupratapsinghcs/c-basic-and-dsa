#include <iostream>
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
int search(int ino[], int data, int strt, int end)
{
    int i;
    for (i = strt; i < end; i++)
    {
        if (ino[i] == data)
        {
            return i;
        }
    }
    return i;
}
Node *solve(int pre[], int ino[], int inStart, int inEnd)
{
    static int preIndex = 0;
    if (inStart > inEnd)
    {
        return NULL;
    }
    Node *newNode = getNewNode(pre[preIndex++]);
    if (inStart == inEnd)
    {
        return newNode;
    }
    // preIndex++;
    int inIndex = search(ino, newNode->data, inStart, inEnd);
    newNode->left = solve(pre, ino, inStart, inIndex - 1);
    newNode->right = solve(pre, ino, inIndex + 1, inEnd);
    return newNode;
}
void inorder(Node *root) // int this treversal the output is sorted
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    int n, m;
    cin >> n;
    int pre[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    cin >> m;
    int ino[m];
    for (int i = 0; i < m; i++)
    {
        cin >> ino[i];
    }
    Node *root = solve(pre, ino, 0, m - 1);
    // inorder(root);
    display(root);
    //3
    // 1 2 3
    // 3
    // 3 2 1

    return 0;
}