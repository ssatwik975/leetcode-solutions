class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int ct = 0;
        vector<int> drow = {-1, 0, +1, 0};
        vector<int> dcol = {0, -1, 0, +1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            time = t;  // Update time to the last timestamp

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] &&
                    grid[nrow][ncol] == 1) {
                        q.push({{nrow, ncol}, t + 1});
                        vis[nrow][ncol] = true;
                        ct++;
                    }
            }
        }

        if (fresh != ct) {
            return -1;  // Not all fresh oranges could rot
        }

        return time;  // Return the time taken for all to rot
    }
};

