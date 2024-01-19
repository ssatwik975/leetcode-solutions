class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));

        for (int i = 0; i < col; i++) {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int rds = 1e9;
                int lds = 1e9;

                int up = matrix[i][j] + dp[i - 1][j];

                if (j > 0) {
                    lds = matrix[i][j] + dp[i - 1][j - 1];
                }

                if (j < col - 1) {
                    rds = matrix[i][j] + dp[i - 1][j + 1];
                }

                dp[i][j] = min(up, min(lds, rds));
            }
        }

        int ans = dp[row - 1][0];
        for (int i = 1; i < col; i++) {
            ans = min(ans, dp[row - 1][i]);
        }

        return ans;
    }
};
