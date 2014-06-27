	int maxProfit(vector<int> &prices) 
    {  
        int minPrice = INT_MAX, profit = 0, maxProfit = 0;
        for(int i= 0; i < prices.size(); i++)
        {
            if(prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            profit = prices[i] - minPrice;
            if(maxProfit < profit)
            {
                maxProfit = profit;
            }
        }
        return maxProfit;
    }  