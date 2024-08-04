class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize the queue with all 0s and set their distance to 0
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        // Perform multi-source BFS
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                // Check if the new position is within bounds and has not been visited
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == INT_MAX) {
                    // Update the distance and push the new cell to the queue
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};

