	int removeDuplicates(int A[], int n)
    {
        if(n == 0) return 0;
        int pre = 0, count = 1;
        for(int i = 1; i < n; i++)
        {
            if(A[i] == A[pre])
            {
                if(count == 2)
                {
                    continue;
                }
                count++;
            }
            else
            {
                count = 1;
            }
            pre++;
            A[pre] = A[i];
        }
        return pre + 1;
    }