//http://fisherlei.blogspot.com/2013/01/leetcode-balanced-binary-tree-solution.html

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) 
	{  
		if(root == NULL) return true;  
		int val = GetBalance(root);  
		if(val ==-1) return false;  
		return true;      
    }    
	int GetBalance(TreeNode* node)  
    {  
		if(node == NULL)  
			return 0;  
		int left = GetBalance(node->left);  
		if(left == -1) return -1;  
		int right = GetBalance(node->right);  
		if(right == -1) return -1;  
		if(left-right>1 || right-left>1)  
			return -1;  
		return left>right? left+1:right+1;  
    }   
     
};



//http://yucoding.blogspot.com/2012/12/leetcode-question-7-balanced-binary-tree.html

class Solution {
public:
    int maxDepth(TreeNode * root)
	{
        if (root==NULL){return 0;}
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
     
    bool testNode(TreeNode * root)
	{
        if (root==NULL) {return true;}
        if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1) {return false;}
        return (testNode(root->left) && testNode(root->right));
    }
     
     
    bool isBalanced(TreeNode *root) 
	{
        return testNode(root);
    }
     
};