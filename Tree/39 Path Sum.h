//http://fisherlei.blogspot.com/2013/03/leetcode-path-sum-solution.html

class Solution {
public:
    bool hasPathSum(TreeNode *root, int target_sum)
	{  
		return hasPathSum(root, 0, target_sum);      
    }  
    bool hasPathSum(TreeNode *root, int path_sum, int target_sum) 
	{  
		if(root == NULL) return false;  
		path_sum += root->val;  
		if(root->left == NULL && root->right == NULL) //leaf  
		{  
			if(path_sum == target_sum)  
			return true;  
			else  
			return false;  
		}  
		return hasPathSum(root->left, path_sum, target_sum) || hasPathSum(root->right, path_sum, target_sum);      
    }  
};

//http://yucoding.blogspot.com/2013/04/leetcode-question-66-path-sum-i.html

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) 
	{
        if (root==NULL) {return false;}
        if ( (root->left==NULL) && (root->right==NULL) && (sum-root->val==0) ) {return true;}
        return (hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val));
    }
};