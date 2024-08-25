class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev (n, 0);
        vector<int> curr (n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) curr[0] = grid[0][0];
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = curr[j-1];
                    curr[j] = grid[i][j] + min(left, up);
                }
                prev = curr;
            }
        }
        return curr[n-1];
    }
};
