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
int isSameStructure(Node *first, Node *second)
{
	if (first == NULL && second == NULL)
	{
		return 1;
	}
	if (first != NULL && second != NULL)
	{
		return (isSameStructure(first->left, second->left) && isSameStructure(first->right, second->right));
	}
	return 0;
}

int main()
{
	Node *roota = insert(NULL);
	Node *rootb = insert(NULL);
	int res = isSameStructure(roota, rootb);
	// sample test case
	// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
	// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
	if (res)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	return 0;
}