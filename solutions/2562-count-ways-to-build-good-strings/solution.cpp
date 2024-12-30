class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= high; ++i) {
            if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % MOD;
            if (i >= one) dp[i] = (dp[i] + dp[i - one]) % MOD;
        }
        int result = 0;
        for (int i = low; i <= high; ++i) {
            result = (result + dp[i]) % MOD;
        }
        return result;
    }
};

