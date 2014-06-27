//http://yucoding.blogspot.com/2013/04/leetcode-question-67-path-sum-ii.html

class Solution {
public:
    vector<vector<int> > allsol;
    vector<int> sol;
    void findSol(TreeNode* root, int sum)
	{
        if ( (root->left==NULL) && (root->right==NULL) && (sum-root->val==0) ) 
		{ 
            sol.push_back(root->val); 
            allsol.push_back(sol);
            return;    
        }
        sol.push_back(root->val);
        if (root->left !=NULL)
		{
            findSol(root->left, sum-root->val);
            sol.pop_back();
        }
        if (root->right!=NULL)
		{
			findSol(root->right, sum-root->val);    
			sol.pop_back();
        }    
    }
     
    vector<vector<int> > pathSum(TreeNode *root, int sum) 
	{
        sol.clear();
        allsol.clear();
        if (root==NULL) {return allsol;}
        findSol(root, sum);
        return allsol;
    }
};



//http://fisherlei.blogspot.com/2012/12/leetcode-path-sum-ii.html
    vector<vector<int> > pathSum(TreeNode *root, int sum) 
	{  
      vector<vector<int> > collect;  
      vector<int> solution;  
      if(root!=NULL)  
        GetPath(root, sum, 0, solution, collect);  
      return collect;  
    }  
    void GetPath(TreeNode* node, int sum, int cal, vector<int>& solution, vector<vector<int> >& collect)  
    {   
      solution.push_back(node->val);  
      cal += node->val;  
      if(cal == sum && node->left == NULL && node->right == NULL)  
      {  
        collect.push_back(solution);        
      }  
      else  
      {      
        if(node->left != NULL)  
        {        
          GetPath(node->left, sum, cal, solution, collect);        
        }  
        if(node->right != NULL)  
        {        
          GetPath(node->right, sum, cal, solution, collect);  
        }  
      }  
      solution.pop_back();  
      cal -= node->val;  
      return;  
    }  