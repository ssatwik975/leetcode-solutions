class Solution {
public:
    bool nomad(vector<vector<int>>& dp, vector<int>& nums, int target, int n) {
        if (target == 0) return true;
        if (n == 0 && target != 0) return false;
        if (dp[n][target] != -1) return dp[n][target];

        bool pick = false;
        if (nums[n] <= target) {
            pick = nomad(dp, nums, target - nums[n], n - 1);
        }
        bool notpick = nomad(dp, nums, target, n - 1);
        
        dp[n][target] = pick || notpick;
        return dp[n][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return false;
        int total = 0;
        for (auto x : nums) total += x;
        int target = total / 2;
        if (target * 2 != total) return false;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return nomad(dp, nums, target, n - 1);
    }
};

