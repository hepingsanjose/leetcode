	int removeElement(int A[], int n, int elem) 
	{
        if(n == 0) return 0;
        int cur = 0;
        for(int i = 0; i < n; i++)
        {
            if(A[i] == elem)
                continue;
            A[cur] = A[i];
            cur++;
        }
        return cur;
    }