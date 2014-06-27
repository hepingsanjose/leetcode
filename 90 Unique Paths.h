// DP, Step[i][j] = Step[i-1][j] + Step[i][j-1];
// http://fisherlei.blogspot.com/2013/01/leetcode-unique-paths.html
// Use this solution, so smart!
	int uniquePaths(int m, int n) 
	{  
		vector<int> maxV(n,0);  
        maxV[0]=1;  
        for(int i =0; i< m; i++)  
        {  
            for(int j =1; j<n; j++)  
			{  
                maxV[j] = maxV[j-1] + maxV[j];  
            }  
        }  
        return maxV[n-1];  
    }

// http://yucoding.blogspot.com/2013/04/leetcode-question-116-unique-path-i.html

	int uniquePaths(int m, int n) 
	{
        int **arr = new int* [m];
        for (int i=0;i<m;i++)
		{
            arr[i]= new int[n];
        }
        arr[0][0]=1;
        for (int i=0;i<m;i++)
		{
            arr[i][0] = 1;
        }
        for (int i=0;i<n;i++)
		{
            arr[0][i] = 1;
        }
        for (int i=1;i<m;i++)
		{
            for(int j=1;j<n;j++)
			{
                arr[i][j] = arr[i][j-1] + arr[i-1][j];
            }
        }   
        return arr[m-1][n-1];
    }	