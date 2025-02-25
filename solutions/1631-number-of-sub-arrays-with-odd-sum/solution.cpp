const int mod = 1e9 + 7;

class Solution {
public:
    int numOfSubarrays(vector<int>& a) {
        int n = a.size();
        
        for(auto &ele : a)
            ele %= 2;
        
        vector<int> dp_zero(n), dp_one(n);
        
        if(a[n - 1] == 0)
            dp_zero[n - 1] = 1;
        else
            dp_one[n - 1] = 1;
        

        for(int i = n - 2; i >= 0; i--)
        {
            if(a[i] == 1)
            {
                dp_one[i] = (1 + dp_zero[i + 1])%mod;
                
                dp_zero[i] = dp_one[i + 1];
            }
            
            if(a[i] == 0)
            {
                dp_zero[i] = (1 + dp_zero[i + 1])%mod;
                
                dp_one[i] = dp_one[i + 1];
            }
            
        }
        
        int sum = 0;
        for(auto ele : dp_one)
            sum += ele, sum %= mod;
        
        return sum;
        
        
    }
};
