//http://fisherlei.blogspot.com/2012/12/leetcode-minimum-depth-of-binary-tree.html
//Recursive solution

int minDepth(TreeNode *root) {  
	if(root == NULL)  
		return 0;  
	int lmin = minDepth(root->left);  
	int rmin = minDepth(root->right);  
	if(lmin ==0 && rmin ==0)  // If both left and right child are empty, the depth of tree is 1.
		return 1;  
	if(lmin ==0)  // If the depth of left child is 0, the left child is empty, we should not count its depth.
	{  
		lmin = INT_MAX;  
	}  
	if(rmin ==0)  // If the depth of right child is 0, the right child is empty, we should not count its depth.
	{  
		rmin = INT_MAX;  
	}  
	return min(lmin, rmin) +1;  
}  

//http://yucoding.blogspot.com/2013/01/leetcode-question-55-minimum-depth-of.html
//Iterative solution
/*Analysis:
Both DFS and BFS can work for this problem. Since the aim is to find the shortest path, BFS might be a better idea. 
A queue is used to save every node from the binary tree in depth order. Pop each node, and push its left child and right child (if exist). 
If the current node is the leaf node (no left and right children), return its depth.  
To store the depth of each node, we can use a pair structure <TreeNode* int>.
Note: 
pair<TreeNode*, int> is a good data structure to save the node as well as its depth.
pair constructor  :   (1) pair<TreeNode* int>(node, dep);
                              (2) make_pair(node,dep);*/

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
    int minDepth(TreeNode *root) {
        queue< pair<TreeNode*,int> > q;
        int i=0;
        if (!root){return 0;}
        q.push(make_pair(root,1));
        while(!q.empty()){
            pair<TreeNode*,int> cur = q.front();
            q.pop();
            if (!cur.first->left && !cur.first->right){
                return cur.second;
            }
            if(cur.first->left){
                q.push(make_pair(cur.first->left,cur.second+1));
            }
            if(cur.first->right){
                q.push(make_pair(cur.first->right,cur.second+1));
            }
        }
    }
};