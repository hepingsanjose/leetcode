//http://fisherlei.blogspot.com/2012/12/leetcode-maximum-depth-of-binary-tree.html

int maxDepth(TreeNode *root) {  
	if(root == NULL)  
		return 0;  
    int lmax = maxDepth(root->left);  
    int rmax = maxDepth(root->right);  
    return max(lmax, rmax)+1;  
    }  
	

//http://yucoding.blogspot.com/2013/01/leetcode-question-48-maximum-depth-of.html

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
    int maxDepth(TreeNode *root) {
        if (!root){return 0;}
        else{
            return max(maxDepth(root->right)+1,maxDepth(root->left)+1);
        }
    }
};


//Iterative solution

int maxDepthIterative(BinaryTree *root) {
  if (!root) return 0;
  stack<BinaryTree*> s;
  s.push(root);
  int maxDepth = 0;
  BinaryTree *prev = NULL;
  while (!s.empty()) {
    BinaryTree *curr = s.top();
    if (!prev || prev->left == curr || prev->right == curr) {
      if (curr->left)
        s.push(curr->left);
      else if (curr->right)
        s.push(curr->right);
    } else if (curr->left == prev) {
      if (curr->right)
        s.push(curr->right);
    } else {
      s.pop();
    }
    prev = curr;
    if (s.size() > maxDepth)
      maxDepth = s.size();
  }
  return maxDepth;
}