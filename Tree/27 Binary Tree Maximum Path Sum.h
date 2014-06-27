// http://fisherlei.blogspot.com/2013/01/leetcode-binary-tree-maximum-path-sum.html
// Use this solution
	int maxPathSum(TreeNode *root) 
	{  
		int maxAcrossRoot=INT_MIN;  
		int maxEndByRoot = GetMax(root, maxAcrossRoot);  
		return max(maxAcrossRoot, maxEndByRoot);  
    }  
    int GetMax(TreeNode *node, int& maxAcrossRoot)  
    {  
		if(node == NULL) 
			return 0;  
		int left = GetMax(node->left, maxAcrossRoot);  
		int right = GetMax(node->right, maxAcrossRoot);  
		int cMax = node->val;  
		if(left>0)  
			cMax+=left;  
		if(right>0)  
			cMax+=right;  
		maxAcrossRoot = max(maxAcrossRoot, cMax);  
		return max(node->val, max(node->val+left, node->val+right));  
    }  
	
// http://yucoding.blogspot.com/2012/12/leetcode-question-13-binary-tree.html

	int max_s;
    int dfs(TreeNode *root)
	{ 
		if (!root) 
		{
			return 0;
		}
		int l = dfs(root->left);
        int r = dfs(root->right);
        int m = root->val;
        if (l>0) {m+=l;}
        if (r>0) {m+=r;} 
        max_s = max(max_s,m);
        if (max(l,r)>0) 
		{ 
			return (max(l,r)+root->val); 
		}
        else 
		{
			return root->val;
		}
    }
    int maxPathSum(TreeNode *root) 
	{
		max_s = INT_MIN;
        dfs(root);
        return max_s; 
    }