class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int ans = INT_MAX;
        vector<int> prev(m, INT_MAX);
        
        for (int i = 0; i < m; i++) {
            for (int j = triangle[i].size() - 1; j >= 0; j--) {
                if (i == 0) {
                    prev[j] = triangle[i][j];
                } else {
                    int first = INT_MAX;
                    if (j > 0) first = prev[j-1];
                    int second = prev[j];

                    prev[j] = triangle[i][j] + min(first, second);
                }
                if (i == m - 1) {
                    ans = min(ans, prev[j]);
                }
            }
        }
        return ans;
    }
};

