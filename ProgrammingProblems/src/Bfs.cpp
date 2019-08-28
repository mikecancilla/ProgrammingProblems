// BFS: Use a queue

#include <iostream>
#include <memory>
#include <queue>

#define UNIQUE_PTR 0

class BfsNode
{
public:

    int value;
#if UNIQUE_PTR
    std::unique_ptr<BfsNode> left;
    std::unique_ptr<BfsNode> right;
#else
    std::shared_ptr<BfsNode> left;
    std::shared_ptr<BfsNode> right;
#endif

    BfsNode(int value)
    : value(value)
    {
        std::cout << "Constructed BfsNode(" << value << ")" << std::endl;
    }

    ~BfsNode()
    {
        std::cout << "Destructed BfsNode(" << value << ")" << std::endl;
    }
};

#if UNIQUE_PTR
void BFSSearch(std::queue<std::unique_ptr<BfsNode>> *q)
{
    if(0 == q->size())
        return;

    if(nullptr != q->front())
    {
        std::cout << q->front()->value << std::endl;
        q->push(std::move(q->front()->left));
        q->push(std::move(q->front()->right));
    }

    q->pop();

    BFSSearch(q);
}

void DoBFS()
{
    std::unique_ptr<BfsNode> root = std::make_unique<BfsNode>(1);

    root->left = std::make_unique<BfsNode>(2);
    root->right = std::make_unique<BfsNode>(3);
    root->left->left = std::make_unique<BfsNode>(4);
    root->left->right = std::make_unique<BfsNode>(5);

    root->right->left = std::make_unique<BfsNode>(6);
    root->right->right = std::make_unique<BfsNode>(7);

    root->right->right->left = std::make_unique<BfsNode>(8);

    std::queue<std::unique_ptr<BfsNode>> q;
    q.push(std::move(root));

    BFSSearch(&q);
}
#else
void BFSSearch(std::queue<std::shared_ptr<BfsNode>> *q)
{
    if(0 == q->size())
        return;

    if(nullptr != q->front())
    {
        std::cout << q->front()->value << std::endl;
        q->push(q->front()->left);
        q->push(q->front()->right);
    }

    q->pop();

    BFSSearch(q);
}

void DFSSearch(std::shared_ptr<BfsNode> node)
{
    if(nullptr == node)
        return;

    std::cout << node->value << std::endl;

    DFSSearch(node->left);
    DFSSearch(node->right);
}

void DoBFSDFS()
{
    std::shared_ptr<BfsNode> root = std::make_shared<BfsNode>(1);

    root->left = std::make_shared<BfsNode>(2);
    root->right = std::make_shared<BfsNode>(3);
    root->left->left = std::make_shared<BfsNode>(4);
    root->left->right = std::make_shared<BfsNode>(5);

    root->right->left = std::make_shared<BfsNode>(6);
    root->right->right = std::make_shared<BfsNode>(7);

    root->right->right->left = std::make_shared<BfsNode>(8);

    // BFS Search
    //std::queue<std::shared_ptr<BfsNode>> q;
    //q.push(std::move(root));
    //BFSSearch(&q);

    // DFS Search
    DFSSearch(root);
}
#endif