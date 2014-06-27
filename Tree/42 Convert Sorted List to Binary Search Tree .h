/*But for linked list, we can't do that because Top-To-Bottom are heavily relied on the index operation.
There is a smart solution to provide an Bottom-TO-Top as an alternative way, 
http://leetcode.com/2010/11/convert-sorted-list-to-balanced-binary.html

As usual, the best solution requires you to think from another perspective. 
In other words, we no longer create nodes in the tree using the top-down approach. 
We create nodes bottom-up, and assign them to its parents. 
The bottom-up approach enables us to access the list in its order while creating nodes.*/


// http://yucoding.blogspot.com/2012/12/leetcode-question-24-convert-sorted.html

class Solution {
public:
 
    TreeNode *l2bst(ListNode* &head,int st, int ed)
	{
        if (st>ed) {return NULL;}
        TreeNode *lefttree = l2bst(head,st,int(st+(ed-st)/2)-1);
        TreeNode *parent = new TreeNode(head->val); 
        head = head->next;
        TreeNode *righttree = l2bst(head,int(st+(ed-st)/2)+1,ed);
        parent->left  = lefttree;
        parent->right  = righttree;
        return parent;
    }
     
    TreeNode *sortedListToBST(ListNode *head) 
	{
        if (head==NULL){return NULL;}
        ListNode *h=head;
        int len = 0;
        while (h){
            len = len+1;
            h = h->next;
        }
        TreeNode *root=l2bst(head,1,len);
        return root;
 
    }
};


//http://fisherlei.blogspot.com/2013/01/leetcode-convert-sorted-list-to-binary.html

	TreeNode *sortedListToBST(ListNode *head)
	{  
		int len =0;  
		ListNode *p = head;  
		while(p)  
		{  
			len++;  
			p = p->next;  
		}  
		return BuildBST(head, 0, len-1);  
	}  
	
	TreeNode* BuildBST(ListNode*& list, int start, int end)  
	{  
		if (start > end) return NULL;  
		int mid = start + (end - start)/2;   //if use start + (end - start) >> 1, test case will break, strange!
		TreeNode *leftChild = BuildBST(list, start, mid-1);  
		TreeNode *parent = new TreeNode(list->val);  
		parent->left = leftChild;  
		list = list->next;  
		parent->right = BuildBST(list, mid+1, end);  
		return parent;  
	}  

