/*
This problem was asked by Google.

Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.

Design a binary tree node class with the following methods:

	is_locked, which returns whether the node is locked
	lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return true.
	unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true.

You may augment the node to add parent pointers or any other property you would like. You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the height of the tree.
*/

class Node
{
public:
	bool locked;
	Node *parent;
	Node *left;
	Node *right;

	Node() :
		locked(false),
		parent(nullptr),
		left(nullptr),
		right(nullptr) {}

	bool is_locked() { return locked; }
};

bool AreParentsLocked(Node *node)
{
	if(nullptr == node)
		return false;

	if(node->is_locked())
		return true;

	return AreParentsLocked(node->parent);
}

bool AreChildrenLocked(Node *node)
{
	if(nullptr == node)
		return false;

	if(node->is_locked())
		return true;

	if(AreChildrenLocked(node->left) ||
	   AreChildrenLocked(node->right))
		return true;
}

bool lock(Node *node)
{
	if(!AreParentsLocked(node) &&
       !AreChildrenLocked(node))
	{
		node->locked = true;
		return true;
	}

	return false;
}

bool unlock(Node *node)
{
	if(!AreParentsLocked(node->parent) &&
       !AreChildrenLocked(node->left) &&
       !AreChildrenLocked(node->right))
	{
		node->locked = false;
		return true;
	}

	return false;
}

bool lock(Node *node)
{
	if(!AreParentsLocked(node->parent) &&
       !AreChildrenLocked(node->left) &&
       !AreChildrenLocked(node->right))
	{
		node->locked = true;
		return true;
	}

	return false;
}

void DoLockBinaryTree()
{
	Node *node = nullptr;

}