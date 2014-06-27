//http://yucoding.blogspot.com/2013/05/leetcode-question115-unique-binary.html

	void dfs(int st,int ed,vector<TreeNode *> &res)
	{
        if (st>ed)
		{
            res.push_back(NULL);
        }
		else
		{
            for (int i=st;i<=ed;i++)
			{
                vector<TreeNode *> lefts;
                dfs(st,i-1,lefts);
                vector<TreeNode *> rights;
                dfs(i+1,ed,rights);
                 
                for (int li = 0; li<lefts.size();li++) 
				{
                    for (int ri =0; ri<rights.size();ri++)
					{
                        TreeNode* node = new TreeNode(i);
                        node->left=lefts[li];
                        node->right=rights[ri];
                        res.push_back(node);
                    }
                }
            }
        }
    }
     
    vector<TreeNode *> generateTrees(int n) 
	{
        vector<TreeNode*> res;
        dfs(1,n,res);
        return res;
    }
	
//http://fisherlei.blogspot.com/2013/03/leetcode-unique-binary-search-trees-ii.html

	vector<TreeNode *> generateTrees(int n) 
	{   
		if(n ==0) return *generate(1,0);  
		return *generate(1, n);  
	}
	
	vector<TreeNode *>* generate(int start, int end)  
	{  
		vector<TreeNode *> *subTree = new vector<TreeNode*>();  
		if(start>end)  
		{  
			subTree->push_back(NULL);  
			return subTree;  
		}  
		for(int i =start; i<=end; i++)  
		{  
			vector<TreeNode*> *leftSubs = generate(start, i-1);  
			vector<TreeNode*> *rightSubs = generate(i+1, end);  
			for(int j = 0; j< leftSubs->size(); j++)  
			{  
				for(int k=0; k<rightSubs->size(); k++)  
				{  
					TreeNode *node = new TreeNode(i);  
					node->left = (*leftSubs)[j];  
					node->right = (*rightSubs)[k];  
					subTree->push_back(node);  
				}  
			}  
		}  
		return subTree;  
	}      