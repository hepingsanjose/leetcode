//http://yucoding.blogspot.com/2012/12/leetcode-question-23-convert-sorted.html

class Solution {
public:
 
    TreeNode* cbst(vector<int> &num, int st, int ed){
        if (st>ed){
            return NULL;
        }else{
            int mid = st+(ed-st)/2;
            TreeNode *bst=new TreeNode(num[mid]);
            bst->left = cbst(num,st,mid-1);
            bst->right = cbst(num,mid+1,ed);
            return bst;
        }
    }
 
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size()==0){return NULL;}
        return cbst(num,0,num.size()-1);
    }
};


//http://fisherlei.blogspot.com/2013/03/leetcode-convert-sorted-array-to-binary.html

	TreeNode *sortedArrayToBST(vector<int> &num) 
	{
		if(num.size() == 0) return NULL;
		return BuildTree(num, 0, num.size()-1);  
	}  
	TreeNode *BuildTree(vector<int> &num, int start, int end)  
	{  
		if(start>end) return NULL;  
		if(start == end) return new TreeNode(num[start]);  
		int mid = start + (end - start)/2;  
		TreeNode *node = new TreeNode(num[mid]);  
		node->left = BuildTree(num, start, mid-1);  
		node->right = BuildTree(num, mid+1, end);  
		return node;  
	}  