class Node
{
public:
	int value;
	Node *left;
	Node *right;
};

// From my understanding initially, that a unival tree only needs to be looked at one depth lower.
/*
int IsUnival(Node* node)
{
	int result = 0;

	if (nullptr == node->left &&
		nullptr == node->right)
		return 1;

	if (nullptr != node->left &&
		nullptr == node->right)
		result += IsUnival(node->left);

	if (nullptr != node->right &&
		nullptr == node->left)
		result += IsUnival(node->right);

	if (node->value ==
		node->left->value ==
		node->right->value)
		result = 1;

	result += IsUnival(node->left) + IsUnival(node->right);

	return result;
}
*/

bool IsUnival(Node* node)
{
	if (nullptr == node)
		return true;

	if (nullptr != node->left &&
		node->value != node->left->value)
		return false;

	if (nullptr != node->right &&
		node->value != node->right->value)
		return false;

	if (IsUnival(node->left) & IsUnival(node->right))
		return true;

	return false;
}

int CountUnivals(Node* node)
{
	if (nullptr == node)
		return 0;

	int total_count = CountUnivals(node->left) + CountUnivals(node->right);

	if (IsUnival(node))
		total_count += 1;

	return total_count;
}

void DoUnival()
{
	Node* node = nullptr;

	int total = CountUnivals(node);
}