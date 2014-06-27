// Preorder Traversal recursive solution; preorder: middle->left->right;

	void preOrder(TreeNode *root, vector<int> &res)
	{
        if (root!=NULL)
		{
            res.push_back(root->val);
            preOrder(root->left,res);
            preOrder(root->right,res);
        }
    }
    vector<int> preorderTraversal(TreeNode *root) 
	{
        vector<int> res;    
        preOrder(root,res);
        return res;
    }
	
//Preorder Traversal iterative solution;

class Solution {
public:
    void preOrder(TreeNode *root, vector<int> &result){
        stack<TreeNode *> treeStack;
        treeStack.push(root);
        while(!treeStack.empty())
        {
            root = treeStack.top();
            treeStack.pop();
            if(root != NULL)
            {
                result.push_back(root->val);
                treeStack.push(root->right);
                treeStack.push(root->left);
            }
        }
    }
    vector<int> preorderTraversal(TreeNode *root) 
	{
        vector<int> result;    
        preOrder(root,result);
        return result;
    }
};
