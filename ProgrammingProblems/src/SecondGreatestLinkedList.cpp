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

unsigned int FindSecondGreatest(Node *node)
{
    if(nullptr == node->right)
        return node->parent->value;

    FindSecondGreatest(node->right);
}

void DoSecondGreatestLinkedList()
{
    Node *root;

    unsigned int secondGreatest = FindSecondGreatest(root);
}