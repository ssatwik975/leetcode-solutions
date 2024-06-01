class Solution {
public:
    int scoreOfString(string s) 
    {
        int res = 0, n = s.size();
        for(int i=1;i<n;i++)
            res += abs((s[i] - s[i-1]));     
        return res;
    }
};
