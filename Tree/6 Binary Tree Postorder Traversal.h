// Postorder Traversal recursive solution; postorder: left->right->middle;

	void postOrder(TreeNode *root, vector<int> &res)
	{
        if (root!=NULL)
		{
            postOrder(root->left,res);
            postOrder(root->right,res);
			res.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode *root) 
	{
        vector<int> res;    
        postOrder(root,res);
        return res;
    }
	
//Postorder Traversal iterative solution;
//http://yucoding.blogspot.com/2013/12/leetcode-question-binary-tree-postorder.html

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) 
	{
        stack<TreeNode*> st;
        vector<int> res;
        if (!root){return res;}
        st.push(root);
        TreeNode* head=root;
        while (!st.empty())
		{
            TreeNode* top = st.top();
            if ((top->left==NULL && top->right==NULL)||top->right==head || top->left==head)
			{
                res.push_back(top->val);
                st.pop();
                head = top;
            }
			else
			{
                if (top->right!=NULL)
				{
					st.push(top->right);
				}
                if (top->left!=NULL)
				{
					st.push(top->left);
				}
            }
        }
        return res;
    }
};


//Solution from previous class
// Can't go through the judge!
void postOrder(TreeNode *root, vector<int> &result)
{
	if(!root) return;
	stack<TreeNode *> treeStack;
	stack<TreeNode *> outputStack;
	treeStack.push(root);
	while(!treeStack.empty())
	{
		TreeNode *current = treeStack.top();
		outputStack.push(current);
		treeStack.pop();
		if(current->left)
			treeStack.push(current->left);
		if(current->right)
			treeStack.push(current->right);
	}
	while(!outputStack.empty())
	{
		result.push_back(root->val);
		outputStack.pop();
	}
}

vector<int> postorderTraversal(TreeNode *root) 
	{
        vector<int> result;    
        postOrder(root,result);
        return result;
    }
