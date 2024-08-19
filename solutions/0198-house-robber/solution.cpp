class Solution {
public:
    int here(int n, vector<int> &nums, vector<int> &dp){
        if(n == 0) return nums[0];
        if(dp[n] != -1) return dp[n];
        int pick = nums[n];
        if(n > 1){
            pick += here(n-2, nums, dp);
        }
        
        int notpick = here(n-1, nums, dp);

        return dp[n] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, -1);
        return here(n-1, nums, dp);
    }
};
