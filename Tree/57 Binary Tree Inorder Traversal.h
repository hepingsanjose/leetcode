// Inorder Traversal recursive solution; inorder: left->middle->right;

	void inOrder(TreeNode *root, vector<int> &res)
	{
        if (root!=NULL)
		{
            inOrder(root->left,res);
            res.push_back(root->val);
            inOrder(root->right,res);
        }
    }
    vector<int> inorderTraversal(TreeNode *root) 
	{
        vector<int> res;    
        inOrder(root,res);
        return res;
    }
	
//Inorder Traversal iterative solution;

class Solution {
public:
    void inOrder(TreeNode *root, vector<int> &result)
	{
        stack<TreeNode *> treeStack;
		TreeNode *cur = root;
        while(!treeStack.empty() || cur)
        {
            if(cur)
			{
				treeStack.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = treeStack.top();
				treeStack.pop();
				result.push_back(cur->val);
				cur = cur->right;
			}
        }
    }
    vector<int> inorderTraversal(TreeNode *root) 
	{
        vector<int> result;    
        inOrder(root,result);
        return result;
    }
};