	vector<int> plusOne(vector<int> &digits) 
	{
        
        int n = digits.size(), carry = 1, sum = 0;
        vector<int> result(n, 0);
        for(int i = n - 1; i >= 0; i--)
        {
            sum = carry + digits[i];
            carry = sum / 10;
            result[i] = sum % 10;
        }
        if(carry > 0)
        {
            result.insert(result.begin(), carry);
        }
        return result;
    }