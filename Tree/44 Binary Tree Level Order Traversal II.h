//Just reverse the output of Binary Tree Level Order Traversal

	vector<vector<int> > levelOrderBottom(TreeNode *root) 
	{  
		vector<vector<int> > result;  
		if(root == NULL) return result;  
		queue<TreeNode*> nodeQ;  
		nodeQ.push(root);  
		int nextLevelCnt=0, currentLevelCnt=1;  
		vector<int> layer;  
		int visitedCnt=0;  
		while(nodeQ.size() != 0)  
		{  
			TreeNode* node = nodeQ.front();  
			nodeQ.pop();  
			visitedCnt++;  
			layer.push_back(node->val);  
			if(node->left != NULL)  
			{  
				nodeQ.push(node->left);  
				nextLevelCnt++;  
			}  
			if(node->right != NULL)  
			{  
				nodeQ.push(node->right);  
				nextLevelCnt++;  
			}  
			if(visitedCnt == currentLevelCnt)  
			{  
				visitedCnt =0;  
				currentLevelCnt = nextLevelCnt;  
				nextLevelCnt=0;  
				result.push_back(layer);  
				layer.clear();  
			}  
		} 
		reverse(result.begin(),result.end());
		return result;  
	}  