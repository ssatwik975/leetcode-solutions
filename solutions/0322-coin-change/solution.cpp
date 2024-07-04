class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Create a DP array with amount + 1 elements, initialized to a large value (amount + 1)
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // Base case: no coins needed to make amount 0
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

