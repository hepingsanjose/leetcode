// http://yucoding.blogspot.com/2013/01/leetcode-question-30-flatten-binary.html

	void flatten(TreeNode *root) 
	{
        while (root)
		{
            if (root->left)
			{
                TreeNode* pre=root->left;
                while (pre->right)
				{
					pre = pre->right;
				}
                pre->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root=root->right;
        }
    }