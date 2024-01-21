class Solution {
public:
    int rob(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector <int> dp (n);
        
        for(int i = 0; i < n; i++){
            dp[i] = nums[i];
        }

        for(int i = 2; i<n; i++){
            int twojump = 0;
            int threejump = 0;
             for (int j = 0; j <= i - 2; j++) {
                twojump = max(twojump, dp[j]);
            }

            for (int k = 0; k <= i - 3; k++) {
                threejump = max(threejump, dp[k]);
            }


            dp[i] += max(twojump, threejump);
        }



        int ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};
