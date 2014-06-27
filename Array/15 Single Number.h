// Use XOR (^, 异或)，A XOR A = 0, and A XOR B XOR A = B

	int singleNumber(int A[], int n) 
	{
		int res = A[0];
		for (int i=1; i<n; i++)
		{
			res = res ^ A[i];
		}
        return res;
    }