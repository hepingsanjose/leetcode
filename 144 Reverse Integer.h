// Overflow problem is not solved.

	int reverse(int x) 
	{
        bool isPos = true;
        if(x < 0)
        {
            x = -x;
            isPos = false;
        }
        int res = 0;
        while(x /10 != 0)
        {
            res = res + x % 10;
            res = res * 10;
            x = x /10;
        }
        res = res + x;
        if(isPos)
        {
            return res;
        }
        else
        {
            return -res;
        }
    }