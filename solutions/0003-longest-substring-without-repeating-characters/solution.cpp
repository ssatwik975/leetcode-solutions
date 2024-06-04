class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
		unordered_map<char, int>mp;
        if(s.length() == 0){
            return 0;
        }
		int i = 0, j = 0, n = s.size(), ans = 0;
		while( i<n && j<n)
		{
			if(mp[s[j]] == 0) 
			{
				mp[s[j]]++; 
				ans = max(ans, j-i); 
                j++;
			}
			else
			{
				mp[s[i]]--;
                i++; 
			}
		}
    
		return ans+1;
	}
};
