// first time, scan from left to right; second time scan from right to left; store the number of candies in a new vector.

	int candy(vector<int> &ratings)
	{
		vector <int> candy(ratings.size(), 1);

		for(int i = 1; i < ratings.size(); i++)
		{
			if(ratings[i] > ratings[i - 1])
			{
				candy[i] = candy[i - 1] + 1;
			}
		}
		
		for(int i = ratings.size() - 2; i >= 0; i--)
		{
			if(ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])
			{
				candy[i] = candy[i + 1] + 1;
			}
		}
		int total = 0;
		for(int i = 0; i < ratings.size(); i++)
		{
			total += candy[i];
		}

		return total;
	}