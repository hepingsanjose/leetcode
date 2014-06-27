// http://fisherlei.blogspot.com/2013/02/leetcode-longest-consecutive-sequence.html
// Leetcode judge: Time Limit Exceeded

	int longestConsecutive(vector<int> &num) 
	{  
        unordered_map<int, int> hashmap;            
        for(int i =0; i< num.size(); i++)  
        {  
            hashmap[num[i]] = i;  
        }  
        vector<int> visited(num.size(), 0);  
        int maxV = INT_MIN;  
        for(int i =0; i< num.size(); i++)  
        {  
            if(visited[i]==1) 
				continue;  
            visited[i]=1;  
            int len = 1;  
            int index = num[i]-1;  
            while(hashmap.find(index) != hashmap.end())  
            {  
                visited[hashmap[index]] =1;  
                index--;  
                len++;  
            }  
            index = num[i]+1;  
            while(hashmap.find(index) != hashmap.end())  
            {  
                visited[hashmap[index]] =1;  
                index++;  
                len++;  
            }  
            if(len > maxV)  
                maxV = len;  
        }  
        return maxV;  
    }


// http://yucoding.blogspot.com/2013/05/leetcode-question-129-longest.html
// Leetcode judge: Accepted
	int longestConsecutive(vector<int> &num) 
	{
        unordered_map<int,bool>mp;
        for (int i=0;i<num.size();i++)
		{
            mp[num[i]]=true;
        }
         
        int res=0;
        for (int i=0;i<num.size();i++)
		{
            int mx=1;      
            int fd = num[i];
             
            mp.erase(num[i]);
            while (mp.find(fd+1)!=mp.end())
			{
                mx++;
                mp.erase(fd+1);
                fd++;
            }
             
            fd = num[i];
            while (mp.find(fd-1)!=mp.end())
			{
                mx++;
                mp.erase(fd-1);
                fd--;
            }
             
            if (mx>res){res=mx;}
        }
        return res;
    }