//http://fisherlei.blogspot.com/2013/01/leetcode-validate-binary-search-tree.html

	bool isValidBST(TreeNode *root) 
	{  
		return IsValidBST(root, INT_MIN, INT_MAX);  
    }  
    bool IsValidBST(TreeNode* node, int MIN, int MAX)   
    {  
        if(node == NULL)  
            return true;  
        if(node->val > MIN   
            && node->val < MAX  
            && IsValidBST(node->left,MIN,node->val)  
            && IsValidBST(node->right,node->val,MAX))  
            return true;  
        else   
            return false;  
    }

//http://yucoding.blogspot.com/2013/02/leetcode-question-122-validate-binary.html
//Inorder traverse the tree, the result should be a sequence in ascending order.
	vector<int> orders;
    void inOrder(TreeNode *root)
	{
        if (root==NULL){return;}
        else
		{
            inOrder(root->left);
            orders.push_back(root->val);
            inOrder(root->right);
        }
    }
    bool isValidBST(TreeNode *root) 
	{
        if (root==NULL){return true;}
        orders.clear();
        inOrder(root);
        for (int i=0;i<orders.size()-1;i++)
		{
            if (orders[i]>=orders[i+1])
			{
                return false;
            }
        }
        return true;
    }