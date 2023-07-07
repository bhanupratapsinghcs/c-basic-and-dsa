#include <iostream>
#include <queue>
using namespace std;
class TestTree // In this Tree I have use root as referece variable to pass the function
{

    struct Node
    {
        int data;
        Node *left;
        Node *right;
    };

    Node *GetNewNode(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    void insert(int data, Node **root)
    {
        if (*root == NULL)
        {
            *root = GetNewNode(data);
            return;
        }
        else if ((*root)->data >= data)
        {
            insert(data, &(*root)->left);
        }
        else
        {
            insert(data, &(*root)->right);
        }
    }
    int FindHeight(Node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        return max(FindHeight(root->left), FindHeight(root->right)) + 1;
    }
    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    // int main()
    // {
    //     Node *root = NULL;
    //     insert(15, &root);
    //     insert(10, &root);
    //     insert(20, &root);
    //     insert(25, &root);
    //     cout << FindHeight(root) << endl;
    //     inorder(root);
    // }
};
class Tree // This is the main class for graph implementation
{
public:
    struct Node // this is the basic structure of Tree representation
    {
        int data;
        Node *left;
        Node *right;
    };

public:
    Node *GetNewNode(int data) // this function create new node add in the graph
    {                          // complexity = O(h) in avg/best case & O(n) for worst case
        Node *newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = NULL; // initially Both right & left Node are NULL
        return newNode;
    }
    Node *insert(int data, Node *root) // insertion function
    {
        if (root == NULL) // insertion when root is NULL
        {
            root = GetNewNode(data);
        }
        else if (root->data >= data) // recursion call when data is less then or equal to root
        {
            root->left = insert(data, root->left); // recursion call to insert to insert in root ->left when true
        }
        else // similarly for right for right subtree
        {
            root->right = insert(data, root->right);
        }
        return root; //return true
    }
    bool search(Node *root, int data) // this is similar as inserting element in a tree
    {
        if (root == NULL) // checking if root is NULL that means the tree is empty or
        {                 // after treaversing the whole tree, element is not found
            return false; // and return False
        }
        else if (data < root->data)          // element is smaller then current element
        {                                    // then find element in left tree
            return search(root->left, data); // passing left child as root to search in left tree
        }
        else if (data > root->data)           // element is greater then current element
        {                                     // then find the element in right tree
            return search(root->right, data); // passing right child as root to search in right tree
        }
        else
        {                // element is equal to current element
            return true; // return ture
        }
    }
    int FindMax(Node *root) // to find the Max element in the tree
    {                       // search in the right most side of the tree or right most element of tree
        if (root == NULL)   // tree is empty : SPECIAL CASE
        {
            cout << "Tree is Empty" << endl;
            return -1;
        }
        else if (root->right == NULL) // Base condition when right most child is NULL
        {                             // NO more child in the right
            return root->data;        // return rightmost child data
        }
        return FindMax(root->right); // recursively passing right child to reach right most element
    }
    int FindMin(Node *root) // to find the Min element in the tree
    {                       // search in the left most side of the tree or left most element of tree
        if (root == NULL)   // tree is empty : SPECIAL CASE
        {
            cout << "Tree is Empty" << endl;
            return -1;
        }
        else if (root->left == NULL) // Base condition when left most child is NULL
        {                            // NO more child in the left
            return root->data;       // return leftmost child data
        }
        return FindMax(root->left); // recursively passing left child to reach left most element
    }
    int FindHeight(Node *root) // largest distance from a leaf node to root node
    {
        if (root == NULL) // SPECIAL CASE : when tree is empty
        {
            return -1; // return -1 because we are finding height on the basis of number edges in between root and leaf node
        }
        /*
        * recursively seeaching for max height from root node to each leaf node
        */
        int leftHeight = FindHeight(root->left);   // recursively moving in left
        int rightHeight = FindHeight(root->right); // recursively moving in right
        return max(leftHeight, rightHeight) + 1;   // after reaching leaf node as Null return -1
    }                                              // then +1 to add height of leaf as 0 of max of left and right tree hight
    /**
     * Breadth First Search also know as Level Order traversal
     * In this traversal we first traverse through one entire level of children node s, 
     * before moving to grandchildren traversal
     * 
     * Implementation : We generaly implement it using Queue data structure
     * 
     * We put all the children of node in the queue that we have visited once 
     * and pop out the parent node from the Queue
     * we done this till the Queue is empty
     * as root is first node we put it first in 
     * the Queue and then start the loop
     */
    void LevelOrder(Node *root)
    {
        if (root == NULL) // SPECIAL CASE : when tree is empty
        {
            return;
        }
        queue<Node *> Q; // creating a Queue of Node* type
        Q.push(root);    // putting root in the queue as it first and process when start
        while (!Q.empty())
        {
            Node *current = Q.front(); // getting fornt node / parent
            cout << current->data << " ";
            if (current->left != NULL)  // checking for left child is present
                Q.push(current->left);  // putting left child in the queue
            if (current->right != NULL) // similarly as left child
                Q.push(current->right);
            Q.pop(); // poping out the visited node
        }
        cout << '\n';
    }
    /**
     * Depth First search also known as graph traversal in which deepest node is
     * visited and then backtracked to the parent node if no sibling of that exist
     * 
     * There are 3 DFS tree traversals :
     *  1. PreOrder     -> root is visited first then left and right subtree s
     *  2. InOrder      -> left subtree is visisted first then root and then right subtree
     *  3. PostOrder    -> right subtree is visited first then right subtree and then root 
     * 
     */
    void PreOrder(Node *root) // root is the first element of the output
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        inorder(root->left);
        inorder(root->right);
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
    void PostOrder(Node *root) // root is the last element of the output
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        inorder(root->right);
        cout << root->data << " ";
    }
    /**
     * Method 1 : IsBinarySearchTree
     * 
     * If a tree is BST,then the root element is greater the or equal to left subtree element
     * similarly with right subtree, element are greater then root element 
     * we check this recursivily for all right and left subtree 
     * if it true then return true else false
     *  
     */
    bool IsSubtreeLesser(Node *root, int data) // check left subtree is lesser or equal
    {
        if (root == NULL)
            return true;
        if (root->data <= data &&
            IsSubtreeLesser(root->left, data) && IsSubtreeLesser(root->right, data)) // recursivily checking its childs
        {
            return true; // return true if all left element are smaller or equal
        }
        else
        {
            return false;
        }
    }

    bool IsSubtreeGreater(Node *root, int data) // check right subtree is greater
    {
        if (root == NULL)
            return true;
        if (root->data > data &&
            IsSubtreeGreater(root->left, data) && IsSubtreeGreater(root->right, data)) // recursivily checking its childs
        {
            return true; // return true if all right element are greate
        }
        else
        {
            return false;
        }
    }
    bool IsBinarySearchTree(Node *root) // this function is more expensive as it's time complexity is O(n^2)
    {
        if (root == NULL)
            return true;
        if (IsSubtreeLesser(root->left, root->data) &&   //checking root element for left tree is lesser or equal
            IsSubtreeGreater(root->right, root->data) && // checking root element for right tree is greater
            IsBinarySearchTree(root->left) &&            // again checking for left subtree recursivily
            IsBinarySearchTree(root->right))             // and right subtree and recursivily
        {
            return true; // if all condition are true then return true
        }
        else
            return false;
    }
    /**
     * Method 2 : IsBinarySearchTree
     * 
     * In this, first we find the max of left subtree and campere it with root
     * which is smaller than the root or not similarly we can check with 
     * right subtree by looking it min is more than the root or not
     * We can defined a permicable range for each node and data in that node
     * must be in the rabge (-infinity, +infinity) -> root 
     * 
     */
    bool isBSTUtil(Node *root, int minValue, int maxValue) // this function don't allow dublicate value-> O(n)
    {
        if (root == NULL)
            return true;
        if (root->data <= maxValue && root->data > minValue && //equal sign in root->data <= maxValue make it fit for dublicate value
            isBSTUtil(root->left, minValue, root->data) &&
            isBSTUtil(root->right, root->data, maxValue))
        {
            return true;
        }
        else
            return false;
    }
    bool IsBinarySearchTree2(Node *root)
    {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
    /**
     *  Delete a node from the tree
     */
    Node *FindMinNode(Node *root) // Find the Min in right subtree (helper function)
    {
        if (root == NULL)
            return NULL;
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }
    Node *Delete(Node *root, int data) // first find the element node recursivily
    {
        if (root == NULL)
            return root;
        else if (data < root->data)
            root->left = Delete(root->left, data);
        else if (data > root->data)
            root->right = Delete(root->right, data);
        else // when the element is found
        {
            // case 1: No child
            if (root->left == NULL && root->right == NULL)
            {
                delete root; // simply delete or deteach the leaf node
                root = NULL;
            }
            // case 2: One child
            else if (root->left == NULL)
            {
                Node *temp = root;
                root = root->right; // attach the child as parent and
                delete temp;        // delete the parent
            }
            else if (root->right == NULL)
            {
                Node *temp = root;
                root = root->left;
                delete temp;
            }
            // case 3: Two child
            else
            {
                Node *temp = FindMinNode(root->right);         // find the min right subtree
                root->data = temp->data;                       // replace it root element
                root->right = Delete(root->right, temp->data); // delete min from the tree as well
            }
        }
        return root;
    }
    /**
     * Find the InOrder Successor of the given node
     */
    Node *SearchNode(Node *root, int data) // Helper function for searching node
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (data < root->data)
        {
            return SearchNode(root->left, data);
        }
        else if (data > root->data)
        {
            return SearchNode(root->right, data);
        }
        else
        {
            return root;
        }
    }
    // This function is to find Inorder successor in a BST
    int InOrderSuccessor(Node *root, int data)
    {
        // Search the Node
        Node *current = SearchNode(root, data);
        if (current == NULL)
        {
            cout << "Data not found in tree\n";
            return -1;
        }
        // case 1: Node has right Subtree
        if (current->right != NULL)
        {
            return FindMin(current->right);
        }
        // case 2: NO right Subtree
        else
        {
            Node *successor = NULL;
            Node *ancestor = root;
            while (ancestor != current)
            {
                if (current->data < ancestor->data)
                {
                    successor = ancestor; // this id the deepest node for which current node is in left
                    ancestor = ancestor->left;
                }
                else
                {
                    ancestor = ancestor->right;
                }
            }
            return successor->data;
        }
    }
};
int main()
{
    Tree T;
    Tree::Node *root = NULL;

    root = T.insert(12, root);
    root = T.insert(5, root);
    root = T.insert(3, root);
    root = T.insert(2, root);
    root = T.insert(7, root);
    root = T.insert(6, root);
    root = T.insert(15, root);
    root = T.insert(5, root);
    root = T.insert(13, root);
    root = T.insert(17, root);
    root = T.insert(20, root);
    root = T.insert(18, root);
    cout << "Search : " << 5 << " " << T.search(root, 5) << endl;
    cout << "Min: " << T.FindMin(root) << endl;
    cout << "Max: " << T.FindMax(root) << endl;
    cout << "Height: " << T.FindHeight(root) << endl;
    cout << "Inorder: ";
    T.inorder(root);
    cout << '\n';
    cout << "LevelOrder: ";
    T.LevelOrder(root);
    cout << "PreOrder: ";
    T.PreOrder(root);
    cout << '\n';
    cout << "PostOrder: ";
    T.PostOrder(root);
    cout << '\n';
    cout << "Is Binary tree: " << T.IsBinarySearchTree(root) << endl;
    cout << "Is Binary tree2: " << T.IsBinarySearchTree2(root) << endl;
    // T.Delete(root, 17);
    // cout << "Inorder: ";
    // T.inorder(root);
    // cout << '\n';
    cout << "InOrder Successor of 15 " << T.InOrderSuccessor(root, 15);
}