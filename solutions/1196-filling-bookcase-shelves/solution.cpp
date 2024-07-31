class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        const int N = books.size();
        // trival case
        if (N == 0) return 0;
        // initialize
        vector<int> dp(N+1, INT_MAX);
        dp[0] = 0;
        // DP
        for (int j(1); j <= N; ++j) {
            int curw = 0; 
            int curh = 0;
            int k = 1;
            while (k <= j) {
                curh = max(curh, books[j-k][1]);
                curw += books[j-k][0];
                if (curw > shelf_width) {
                    break;
                }
                dp[j] = min(dp[j], dp[j-k] + curh);
                k += 1;
            }
        }
        return dp[N];
    }
};
