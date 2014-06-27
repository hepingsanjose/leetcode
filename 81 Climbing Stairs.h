// Recursive solution,  Time Limit Exceeded
	int climbStairs(int n)
	{
		if(n <= 2) 
		{
			return n;
		}
		else
		{
			return climbStairs(n-1) + climbStairs(n-2);
		}
	}
	
// DP solution

	int climbStairs(int n)
	{
		vector<int> result(n+1, 0);
		result[1] = 1;
		result[2] = 2;
		for(int i = 3; i <= n; i++)
		{
			result[i] = result[i-1] + result[i-2];
		}
		return result[n];
	}