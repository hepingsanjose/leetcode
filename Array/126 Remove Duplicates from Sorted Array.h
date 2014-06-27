	int removeDuplicates(int A[], int n) 
	{
        if(n == 0)
            return 0;
        int pre = 0;
        for(int i = 1; i < n; i++)
        {
            if(A[i] == A[pre])
            {
                continue;
            }
            pre++;
            A[pre] = A[i];
        }
        return pre+1;
    }