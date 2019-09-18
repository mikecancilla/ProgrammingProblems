/*
https://leetcode.com/problems/subtree-of-another-tree/

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2

Given tree t:
   4 
  / \
 1   2

Return true, because t has the same structure and node values with a subtree of s.

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0

   Given tree t:
   4
  / \
 1   2

Return false.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// BFS -> queue
// 
// If s == t
//    BFSEqual(s, t)
// else
//    push s.left
//    push s.right
//    pop s
// loop

// BFSEqual(s, t)
//
// if(s == NULL & t == NULL)
//    return true;
//
// sQueue.push(s.left);
// sQueue.push(s.right);
// tQueue.push(t.left);
// tQueue.push(t.right);
//
// bEqual = true;
// bDone = false;
//
// while(sQueue.size() && tQueue.size() && !bDone)
// {
//   sNode = sQueue.front;
//   tNode = tQueue.front;
//
//   if(sNode.val != tNode.val)
//   {
//     bDone = true;
//     bEqual = false;
//   }
//
//   if(sNode)
//     sQueue.push(sNode.left);
//     sQueue.push(sNode.right);
//
//   if(tNode)
//     tQueue.push(tNode.left);
//     tQueue.push(tNode.right);
//
//   sQueue.pop
//   tQueue.pop
// }
//
// return bEqual;

void DoSubtreeOfAnotherTree()
{
}

