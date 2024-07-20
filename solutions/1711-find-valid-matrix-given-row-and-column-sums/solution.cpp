class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> m(rowSum.size(), vector<int>(colSum.size()));
        for (int x = 0, y = 0; x < rowSum.size() && y < colSum.size();) {
            m[x][y] = min(rowSum[x], colSum[y]);
            rowSum[x] -= m[x][y];
            colSum[y] -= m[x][y];
            x += rowSum[x] == 0;
            y += colSum[y] == 0;
        }
        return m;
    }
};
