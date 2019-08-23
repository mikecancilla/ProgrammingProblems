/*
This problem was asked by Google.
Given a binary tree of integers, find the maximum path sum between two nodes. The path must go through at least one node, and does not need to go through the root.
*/

/*
- Write a TreeSum() function.
- Do a DFS or BFS over entire tree, calling TreeSum() for each node
- Store the max as you go along
*/

#include <cstdlib>

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node()
        : value(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

void FillTree(Node* &node, int lTotal, int rTotal);

void CreateNode(Node *&node)
{
    node = new Node();
    node->value = rand();
}

void CreateNode(Node *&node, int value)
{
    node = new Node();
    node->value = value;
}

void FillNode(Node* &node, int total)
{
    if(total > 0)
    {
        CreateNode(node);
        total--;

        if(total)
        {
            CreateNode(node->left);
            total--;
        }

        if(total)
        {
            CreateNode(node->right);
            total--;
        }

        if(node->left)
            FillTree(node->left, total--, total--);

        if(node->right)
            FillTree(node->right, total--, total--);
    }

    return;
}

void FillTree(Node* &node, int lTotal, int rTotal)
{
    if(lTotal > 0)
       FillNode(node->left, lTotal);

    if(rTotal > 0)
       FillNode(node->right, rTotal);
}

void DeleteTree(Node* node)
{
    if(node)
    {
        if(node->left)
            DeleteTree(node->left);

        if(node->right)
            DeleteTree(node->right);

        delete node;
        node = nullptr;
    }
}

int MaxTreeSum(Node *root, int &max)
{
    if(nullptr == root)
        return 0;

    int l = MaxTreeSum(root->left, max);
    int r = MaxTreeSum(root->right, max);

    int local_max = root->value;
    if(root->value + l > local_max)
        local_max = root->value + l;
    if(l > local_max)
        local_max = l;

    if(root->value + r > local_max)
        local_max = root->value + r;
    if(r > local_max)
        local_max = r;

    max = max > local_max ? max : local_max;
    return max;
}

// Not sure I got this one correct
void DoMaxTreeSum()
{
    Node *root = nullptr;
    int max = INT_MIN;

    //CreateNode(root);
    //FillTree(root, 4, 3);

    CreateNode(root, 5);
    CreateNode(root->left, -3);
    CreateNode(root->right, 6);

    CreateNode(root->left->left, -2);
    CreateNode(root->left->right, 4);

    CreateNode(root->right->left, 2);
    CreateNode(root->right->right, 4);

    MaxTreeSum(root, max);
    DeleteTree(root);
}