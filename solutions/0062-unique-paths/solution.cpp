// class Solution {
// public:
//     void solve(int row, int col, int m, int n, int& count) {
//         if (row == m - 1 && col == n - 1) {
//             count++;
//             return;
//         }
//         if (row + 1 < m) {
//             solve(row + 1, col, m, n, count);
//         }
//         if (col + 1 < n) {
//             solve(row, col + 1, m, n, count);
//         }
//     }
//     int uniquePaths(int m, int n) {
//         int count = 0;
//         solve(0, 0, m, n, count);
//         return count;
//     }
// };
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D dp array with all elements initialized to 1
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // Fill the dp array
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // The number of ways to reach (i, j) is the sum of the ways
                // to reach the cell directly above (i-1, j) and the cell
                // directly to the left (i, j-1)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        // The bottom-right corner contains the number of unique paths to reach (m-1, n-1)
        return dp[m-1][n-1];
    }
};
