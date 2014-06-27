// http://yucoding.blogspot.com/2012/12/leetcode-question-14-binary-tree-zigzag.html

	vector<vector<int> > zigzagLevelOrder(TreeNode *root) 
	{
        vector<vector<int> > res; //res vector
        if (root!=NULL){
            res.push_back(vector<int>(1,root->val)); // add root to the res; 
			// The first argument for the vector constructor is the number of elements, the second, the value used to fill the vector.
            deque<TreeNode*> q1,q2;
            vector<int> lev;
            q1.push_back(root);
            bool flag = false; //flag to decide the print order
            while (true)
			{
                //level order traversal
                while (!q1.empty())
				{      
                    TreeNode* node = q1.front();
                    q1.pop_front();
                    if (node->left != NULL){q2.push_back(node->left);}
                    if (node->right != NULL){q2.push_back(node->right);}
                }
                if (q2.empty()){return res;}
                q1 = q2;
                //zigzag order print
                while (!q2.empty()){
                    if (flag){
                        lev.push_back(q2.front()->val);
                        q2.pop_front();
                    }else{
                        lev.push_back(q2.back()->val);
                        q2.pop_back();
                    }
                }
                res.push_back(lev);
                lev.clear();
                flag = !flag;
            }
        }
        return res;
    }