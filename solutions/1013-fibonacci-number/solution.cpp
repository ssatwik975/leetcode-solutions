

class Solution {
public:
    int fib(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, int> memo;
        return helper(n, memo);
    }

    int helper(int n, unordered_map<int, int>& memo) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (memo.find(n) != memo.end()) return memo[n];
        memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
        return memo[n];
    }
};

