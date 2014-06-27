#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode *root);
bool isSymmetricNonrecursive(TreeNode *root);
bool helper(TreeNode *left, TreeNode *right);

int main()
{

	return 0;
}

bool isSymmetric(TreeNode *root)
{
	if (root == NULL) return true;
	return helper(root->left, root->right);
}

bool helper(TreeNode *left, TreeNode *right)
{
	if (left == NULL)
		return right == NULL;
	if (right == NULL)
		return left == NULL;
	if (left->val != right->val)
		return false;
	if (!helper(left->left, right->right))
		return false;
	if (!helper(left->right, right->left))
		return false;
	return true;
}

bool isSymmetricNonrecursive(TreeNode *root)
{
	if (root == NULL) return true;
	queue <TreeNode *> q1;
	queue <TreeNode *> q2;

	q1.push(root->left);
	q2.push(root->right);

	while (!q1.empty() && !q2.empty())
	{
		TreeNode *t1 = q1.front();
		TreeNode *t2 = q2.front();
		q1.pop();
		q2.pop();

		if ((t1 != NULL && t2 == NULL) || (t1 == NULL && t2 != NULL))
			return false;

		if (t1 != NULL && t2 != NULL)
		{
			if (t1->val != t2->val)
				return false;
			q1.push(t1->left);
			q1.push(t1->right);
			q2.push(t2->right);
			q2.push(t2->left);
		}
	}
	return true;
}
