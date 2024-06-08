class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<int> rowm(m, 0);
        vector<int> colm(n, 0);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                rowm[i] = max(rowm[i], grid[i][j]);
                colm[j] = max(colm[j], grid[i][j]);
            }
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                ans += min(rowm[i], colm[j]) - grid[i][j];
            }
        }
        return ans;
        

    }
};
