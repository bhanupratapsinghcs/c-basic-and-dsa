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
void inorder(Node *root) // int this treversal the output is sorted
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL && root->right != NULL)
    {
        inorder(root->left);
        inorder(root->right);
    }
    else if (root->left != NULL)
    {
        cout << root->left->data << " ";
        inorder(root->left);
    }
    else if (root->right != NULL)
    {
        cout << root->right->data << " ";
        inorder(root->right);
    }
    return;
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
    Node *roota = insert(NULL);
    inorder(roota);
    // 50 true 12 true 18 false false false false
    return 0;
}