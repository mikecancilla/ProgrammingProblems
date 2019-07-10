/*
This problem was asked by Microsoft.

Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5
You should return 45, as it is (3 + 2) * (4 + 5).
*/

/*
- Read value of current node
  - If math operator return math operator applied to L and R with recusion
  - If number, return number
*/

#include <iostream>
#include <string>
#include <deque>

struct Node
{
    std::string value;
    Node *pLeft;
    Node *pRight;

    Node(std::string value = "", Node *pLeft = nullptr, Node *pRight = nullptr) :
        value(value),
        pLeft(pLeft),
        pRight(pRight)
    {
    }
};

int DoMathRecursion(Node *pNode)
{
    if(nullptr == pNode)
        return 0;

    if ("+" == pNode->value)
        return DoMathRecursion(pNode->pLeft) + DoMathRecursion(pNode->pRight);

    if ("-" == pNode->value)
        return DoMathRecursion(pNode->pLeft) - DoMathRecursion(pNode->pRight);

    if ("*" == pNode->value)
        return DoMathRecursion(pNode->pLeft) * DoMathRecursion(pNode->pRight);

    if ("/" == pNode->value)
        return DoMathRecursion(pNode->pLeft) / DoMathRecursion(pNode->pRight);

    return std::atoi(pNode->value.c_str());
}

#define IS_LEAF_NODE(p) (p->pLeft == nullptr && p->pRight == nullptr)

int eval(Node *pNode)
{
    int i1 = std::atoi(pNode->pLeft->value.c_str());
    int i2 = std::atoi(pNode->pRight->value.c_str());

    if ("+" == pNode->value)
        pNode->value = std::to_string(i1 + i2);
    else if ("-" == pNode->value)
        pNode->value = std::to_string(i1 - i2);
    if ("*" == pNode->value)
        pNode->value = std::to_string(i1 * i2);
    if ("/" == pNode->value)
        pNode->value = std::to_string(i1 / i2);

    pNode->pLeft = nullptr;
    pNode->pRight = nullptr;

    return std::atoi(pNode->value.c_str());
}

int DoMathQueue(Node *pRoot)
{
    if(nullptr == pRoot)
        return 0;

    std::deque<Node*> nodeDeque;

    nodeDeque.push_front(pRoot);

    Node *pNode = nullptr;

    int ret = 0;

    while(!nodeDeque.empty())
    {
        pNode = (Node*) nodeDeque.front();

        if ("+" == pNode->value ||
            "-" == pNode->value ||
            "*" == pNode->value ||
            "/" == pNode->value)
        {
            if(IS_LEAF_NODE(pNode->pLeft) &&
               IS_LEAF_NODE(pNode->pRight))
            {
                ret = eval(pNode);
                nodeDeque.pop_front();
            }
            else
            {
                if(!IS_LEAF_NODE(pNode->pRight))
                    nodeDeque.push_front(pNode->pRight);

                if(!IS_LEAF_NODE(pNode->pLeft))
                    nodeDeque.push_front(pNode->pLeft);
            }
        }
    }

    return ret;
}

void DoArithmeticExpressionBinaryTree()
{
    Node      root;
    Node   l1,     r1;
    Node l2, r2, l3, r3;

/*
    root.value = "+";
    root.pLeft = &l1;
    root.pRight = &r1;

    l1.value = "3";
    l1.pLeft = nullptr;
    l1.pRight = nullptr;

    r1.value = "2";
    r1.pLeft = nullptr;
    r1.pRight = nullptr;
*/

    root.value = "*";
    root.pLeft = &l1;
    root.pRight = &r1;

    l1.value = "+";
    l1.pLeft = &l2;
    l1.pRight = &r2;

    r1.value = "+";
    r1.pLeft = &l3;
    r1.pRight = &r3;

    l2.value = "3";
    l2.pLeft = nullptr;
    l2.pRight = nullptr;

    r2.value = "2";
    r2.pLeft = nullptr;
    r2.pRight = nullptr;

    l3.value = "4";
    l3.pLeft = nullptr;
    l3.pRight = nullptr;

    r3.value = "5";
    r3.pLeft = nullptr;
    r3.pRight = nullptr;

//    std::cout << "Product is: " << DoMathRecursion(&root) << std::endl;
    std::cout << "Product is: " << DoMathQueue(&root) << std::endl;
}