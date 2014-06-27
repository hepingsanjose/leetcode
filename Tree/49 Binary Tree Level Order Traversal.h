// http://yucoding.blogspot.com/2012/12/leetcode-question-12-binary-tree-level_26.html

	vector<vector<int> > levelOrder(TreeNode *root) 
	{
        vector<vector<int> > res; //result vector
        queue<pair<TreeNode*,int> > q; //traversal queue
        vector<int> res_tmp; // level vector
         
        if (!root){return res;}
        q.push(make_pair(root,1)); //push the root into the queue
        int level=1; //previous level
        while (!q.empty())
		{
            pair<TreeNode*,int> tmp = q.front();
            q.pop();
            if (tmp.second!=level) //if current element has a new level
			{ 
                level = tmp.second;
                res.push_back(res_tmp); //push the level vector to result
                res_tmp.clear();  //clear the level vector to store the new level
            }
             
            res_tmp.push_back(tmp.first->val); //push the current value to the level vector
             
            if (tmp.first->left!=NULL)
			{
                q.push(make_pair(tmp.first->left,tmp.second+1));
            }
            if (tmp.first->right!=NULL)
			{
                q.push(make_pair(tmp.first->right,tmp.second+1));
            }
        }
        res.push_back(res_tmp); // the last level also needs to push into the result
        return res;
    }
	
//http://fisherlei.blogspot.com/2013/01/leetcode-binary-tree-level-order.html
// BFS solution
// Use this solution
	vector<vector<int> > levelOrder(TreeNode *root) 
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
		return result;  
	}  