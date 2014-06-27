// http://fisherlei.blogspot.com/2012/12/leetcode-populating-next-right-pointers_29.html
// Recursive solution

	void connect(TreeLinkNode *root) 
	{  
		if(root== NULL) return;  
		TreeLinkNode* p = root->next;  
		while(p!=NULL)  
		{  
			if(p->left!=NULL)  
			{  
				p = p->left;  
				break;  
			}  
			if(p->right!=NULL)  
			{  
				p = p->right;  
				break;  
			}  
			p = p->next;  
		}  
		if(root->right!= NULL)  
		{        
			root->right->next = p;  
		}  
		if(root->left !=NULL)  
		{        
			root->left->next = root->right? root->right:p;        
		}  
		connect(root->right);  
		connect(root->left);      
    }  