class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n));
        
        // Process diagonals starting from last row
        for (int i = n - 1; i >= 0; i--) {
            int k = i, j = 0;
            vector<int> temp;
            while (k < n && j < n) {
                temp.push_back(grid[k][j]);
                k++; j++;
            }
            sort(temp.begin(), temp.end(), greater<int>());
            k = i; j = 0;
            int l = 0;
            while (k < n && j < n) {
                ans[k][j] = temp[l++];
                k++; j++;
            }
        }
        
        // Process diagonals starting from first row
        for (int i = 1; i < n; i++) {
            int r = 0, c = i;
            vector<int> temp;
            while (r < n && c < n) {
                temp.push_back(grid[r][c]);
                r++; c++;
            }
            sort(temp.begin(), temp.end());
            r = 0; c = i;
            int l = 0;
            while (r < n && c < n) {
                ans[r][c] = temp[l++];
                r++; c++;
            }
        }
        
        return ans;
    }
};
