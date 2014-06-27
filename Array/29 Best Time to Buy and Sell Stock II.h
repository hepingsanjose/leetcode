	int maxProfit(vector<int> &prices) 
	{
        int profit = 0, totalProfit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            profit = prices[i] - prices[i-1];
            if(profit > 0)
                totalProfit += profit;
        }
        return totalProfit;
    }