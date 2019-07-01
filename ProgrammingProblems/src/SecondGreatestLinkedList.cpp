/*
This problem was asked by Dropbox.

Given the root to a binary search tree, find the second largest node in the tree.
*/

// - Search to right, keep track of parent.
// - When you reach a leaf, the parent is 2nd largest.

struct Node
{
    unsigned int value;
    Node *parent;
    Node *left;
    Node *right;
};

Node* FindMaxNode(Node* node)
{
    if(node->right)
        FindMaxNode(node->right);

    return node;
}

void DoSecondGreatestLinkedList()
{
    Node *root = nullptr;
    Node *node = nullptr;

    node = FindMaxNode(root);

    // We now have a pointer the the highest value node.
    // The second greatest will be the max of the left sub tree or parent
    if(node->left)
        node = FindMaxNode(node->left);
    else
        node = node->parent;

    // node->value is now second greatest
}