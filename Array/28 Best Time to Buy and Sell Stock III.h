// DP
	int maxProfit(vector<int> &prices) 
    {
        vector<int> lmax;
        int minPrice = INT_MAX, profit = 0, maxProfit = 0; 
        for(int i = 0; i < prices.size(); i++) // maxProfit from left to right
        {
            if(prices[i] < minPrice)
                minPrice = prices[i];
            profit = prices[i] - minPrice;
            if(maxProfit < profit)
                maxProfit = profit;
            lmax.push_back(maxProfit);
        }
        int maxPrice = INT_MIN, totalProfit = 0;
        for(int i = prices.size()-1; i >= 0; i--) // add up the maxprofit of two parts
        {
            if(prices[i] > maxPrice)
                maxPrice = prices[i];
            if(totalProfit < maxPrice - prices[i] + lmax[i])
                totalProfit = maxPrice - prices[i] + lmax[i];
        }
        return totalProfit;
    }