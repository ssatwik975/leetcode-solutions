class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        // Use long long to handle large sums
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        // Step 1: Fill base prices
        for (const auto& price : prices) {
            int h = price[0], w = price[1];
            long long p = price[2];
            dp[h][w] = max(dp[h][w], p);
        }

        // Step 2: DP transition
        for (int h = 1; h <= m; ++h) {
            for (int w = 1; w <= n; ++w) {
                // Try all horizontal cuts
                for (int cut = 1; cut < h; ++cut) {
                    dp[h][w] = max(dp[h][w], dp[cut][w] + dp[h - cut][w]);
                }
                // Try all vertical cuts
                for (int cut = 1; cut < w; ++cut) {
                    dp[h][w] = max(dp[h][w], dp[h][cut] + dp[h][w - cut]);
                }
            }
        }

        return dp[m][n];
    }
};
