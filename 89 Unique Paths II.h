// http://fisherlei.blogspot.com/2013/01/leetcode-unique-paths-ii.html
// similar to Unique Paths, DP
// Step[i][j] = Step[i-1][j] + Step[i][j-1] if Array[i][j] ==0 or Step[i][j] = 0 if Array[i][j] ==1

	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) 
	{  
        int m = obstacleGrid.size();  
        if(m ==0) 
			return 0;  
        int n = obstacleGrid[0].size();  
        if(obstacleGrid[0][0] ==1) 
			return 0;  
        vector<int> maxV(n,0);  
        maxV[0] =1;  
        for(int i =0; i<m; i++)  
        {  
            for(int j =0; j<n; j++)  
            {  
                if(obstacleGrid[i][j] ==1)  
                    maxV[j]=0;  
                else if(j >0)  
                    maxV[j] = maxV[j-1]+maxV[j];  
            }  
        }  
        return maxV[n-1];  
    }  
