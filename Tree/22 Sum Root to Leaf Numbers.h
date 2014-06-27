//http://fisherlei.blogspot.com/2013/02/leetcode-sum-root-to-leaf-numbers.html

int sumNumbers(TreeNode *root) 
{  
	int sum = 0, path = 0;            
	GenerateSum(root, sum, path);  
	return sum;  
}  
void GenerateSum(TreeNode *root, int& sum, int path)  
{  
	if(root == NULL) return;      
	path = path*10 + root->val;  
	if(root->left == NULL && root->right == NULL)  
	{  
		sum += path;  
		return;  
	}  
	GenerateSum(root->left, sum, path);  
	GenerateSum(root->right, sum, path);  
}  

//http://yucoding.blogspot.com/2013/05/leetcode-question-130-sum-root-to-leaf.html

public:
 
    void dfs(TreeNode* root,int cur, int &result){
        if (root->left==NULL && root->right==NULL){
            cur=cur*10+root->val;
            result+=cur;
        }else{
            cur=cur*10+root->val;
            if (root->left){
                dfs(root->left,cur,result);
            }
            if (root->right){
                dfs(root->right,cur,result);
            }
        }
    }
    int sumNumbers(TreeNode *root) {
        int result=0;
        if (!root){return result;}
        dfs(root,0,result);
        return result;
    }
};