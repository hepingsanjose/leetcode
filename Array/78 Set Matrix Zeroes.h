// http://yucoding.blogspot.com/2013/04/leetcode-question-97-set-matrix-zeros.html

	void setZeroes(vector<vector<int> > &matrix) 
	{
        int row = matrix.size();
        if (row==0){return;}
        int col = matrix[0].size();
        if (col==0){return;}
         
        bool fc0=false;
        bool fr0=false;
         
        for (int i=0;i<col;i++) // whether set the first row of matrix to zero
		{
            if (matrix[0][i]==0){fr0 = true;}
        }
         
        for (int i=0;i<row;i++) // whether set the first column of matrix to zero
		{
            if (matrix[i][0]==0){fc0 = true;}
        }
         
        for (int i=1;i<row;i++) // store the information of setting which row and column to zero in the first row and first column
		{
            for (int j=1;j<col;j++)
			{
                if (matrix[i][j]==0)
				{
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
         
         
        for (int i=1;i<col;i++) // set the corresponding columns to zero
		{
            if (matrix[0][i]==0)
			{
                for(int j=0;j<row;j++)
				{
                    matrix[j][i]=0;
                }
            }
        }
         
        for (int i=1;i<row;i++) // set the corresponding rows to zero
		{
            if (matrix[i][0]==0)
			{
                for(int j=0;j<col;j++)
				{
                    matrix[i][j]=0;
                }
            }
        }
         
        if (fr0) // set the first row to zero when necessary
		{
            for (int i=0;i<col;i++){matrix[0][i]=0;}
        }
        if (fc0) // set the first column to zero when necessary
		{
            for (int i=0;i<row;i++){matrix[i][0]=0;}
        }
         
        return;
         
    }