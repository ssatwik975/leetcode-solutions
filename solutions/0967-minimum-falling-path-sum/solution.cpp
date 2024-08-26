class Solution {
public:
    int nomad (vector<vector<int>>&dp,vector<vector<int>>&grid, int r, int c){
        if(r==0 && c >= 0 && c < grid[0].size()) return grid[r][c];
        if(c < 0 || c >= grid.size()) return INT_MAX;
        if(dp[r][c] != INT_MAX) return dp[r][c];
        return dp[r][c] = grid[r][c] + min(nomad(dp, grid, r-1, c-1), min(nomad(dp, grid, r-1, c), nomad(dp, grid, r-1, c+1)));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>>dp (r, vector<int>(c,INT_MAX));
        for(int i = 0; i < r; i++){
            ans = min(ans, nomad(dp, matrix, r-1, i));
        }
        return ans;
    }
};
