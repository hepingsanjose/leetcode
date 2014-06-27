// http://fisherlei.blogspot.com/2012/12/leetcode-populating-next-right-pointers.html

	void connect(TreeLinkNode *root) 
	{  

		if(root == NULL) 
			return;  
		if(root->left != NULL)  
			root->left->next = root->right;  
		if(root->right !=NULL)  
			//root->right->next = root->next? root->next->left:NULL;  
			if(root->next != NULL)
			{
				root->right->next = root->next->left;
			}
			else
			{
				root->right->next = NULL;
			}
		connect(root->left);  
		connect(root->right);  
    }  