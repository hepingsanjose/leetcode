// Still use bit operations, add up the "1" bits of all integers, except for the single number, all other numbers appear three times
// in the array, the sum of "1" mod 3 should be 0, then based on the 0s and 1s of final result, we get the single number.

	int singleNumber(int A[], int n) 
	{
        int single_number = 0;
        for (int i = 0; i < 32; i++) 
		{// assume dealing with int32.
            int bit = 0;
            for (int j = 0; j < n; j++) 
			{
                bit = (bit + ((A[j] >> i) & 1)) % 3;
            }
            single_number += (bit << i);
        }
        return single_number;
    }