// http://yucoding.blogspot.com/2013/04/leetcode-question-114-unique-binary.html

//1. Recursive solution
	int numTrees(int n) 
	{
        if (n==0){return 1;}
        if (n==1){return 1;}
        int sum=0;
        for (int i=1;i<=n;i++){
            sum += numTrees(i-1)*numTrees(n-i);
        }
        return sum;
         
    }
	
//2. DP
	int numTrees(int n) 
	{
        vector<int> table(n+1,0);
        if (n==0){return 0;}
        table[0]=1;
        table[1]=1;
        table[2]=2;
        for (int i=3;i<=n;i++)
		{
            int res=0;
            for (int j=0;j<=i-1;j++)
			{
                res = res+ table[j]*table[i-1-j];
            }
            table[i]=res;
        }
        return table[n];   
    }
	
//http://fisherlei.blogspot.com/2013/03/leetcode-unique-binary-search-trees.html
//DP
	int numTrees(int n) 
	{  
		vector<int> count(n+1, 0);  
		count[0] =1;  
		count[1] =1;  
		for(int i =2; i<=n; i++)  
		{  
			for(int j =0; j<i; j++)  
			{  
				count[i] += count[j]*count[i-j-1];   
			}  
		}  
		return count[n];  
	}  