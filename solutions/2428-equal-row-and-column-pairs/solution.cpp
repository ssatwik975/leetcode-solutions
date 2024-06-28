class Solution {
public:
    vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> transposed(n, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                transposed[j][i] = matrix[i][j];
            }
        }
        return transposed;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> transposedGrid = transposeMatrix(grid);
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i] == transposedGrid[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};
