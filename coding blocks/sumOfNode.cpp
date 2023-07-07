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
        // cout << "parent" << endl;
        int data;
        cin >> data;
        root = getNewNode(data);
        return insert(root);
    }
    bool hasLeftChild, hasRightChild;
    // cout << "left " << root->data << endl;
    cin >> std::boolalpha >> hasLeftChild;
    if (hasLeftChild)
    {
        root->left = insert(root->left);
    }
    // cout << "right " << root->data << endl;
    cin >> std::boolalpha >> hasRightChild;
    if (hasRightChild)
    {
        root->right = insert(root->right);
    }
    // cout << root->data << endl;
    return root;
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
void inorderSum(Node *root, int &sum) // int this treversal the output is sorted
{
    if (root == NULL)
    {
        return;
    }
    inorderSum(root->left, sum);
    sum += root->data;
    inorderSum(root->right, sum);
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
    int sum = 0;
    inorderSum(roota, sum);
    cout << sum << endl;
    // sample Test Case
    // 50 true 25 true 12 false false false true 75 true 62 false false false
    return 0;
}