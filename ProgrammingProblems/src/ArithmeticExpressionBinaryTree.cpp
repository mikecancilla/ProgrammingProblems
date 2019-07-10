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

struct Node
{
    std::string value;
    Node *pLeft;
    Node *pRight;
};

int DoMath(Node *pNode)
{
    if(nullptr == pNode)
        return 0;

    if ("+" == pNode->value)
        return DoMath(pNode->pLeft) + DoMath(pNode->pRight);

    if ("-" == pNode->value)
        return DoMath(pNode->pLeft) - DoMath(pNode->pRight);

    if ("*" == pNode->value)
        return DoMath(pNode->pLeft) * DoMath(pNode->pRight);

    if ("/" == pNode->value)
        return DoMath(pNode->pLeft) / DoMath(pNode->pRight);

    return std::atoi(pNode->value.c_str());
}

void DoArithmeticExpressionBinaryTree()
{
    Node      root;
    Node   l1,     r1;
    Node l2, r2, l3, r3;

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

    std::cout << "Product is: " << DoMath(&root) << std::endl;
}