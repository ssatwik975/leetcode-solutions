class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // gonna write multisource bfs marking all islands connected to boundary Os
        // as untouchable, and then I'll just convert everything else to X;
        // so lemme just make a matrix of Xs and that will be my answer matrix;

        int n = board.size();
        int m = board[0].size();
        vector<vector<char>> ans(n, vector<char>(m, 'X'));
        queue<pair<int, int>> q;

        // Initialize the queue with all boundary 0s and set them in the ans matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(i >= 1 && i < n-1 && j >= 1 && j < m-1){
                    continue;
                }
                if (board[i][j] == 'O') {
                    q.push({i, j});
                    ans[i][j] = 'O';
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
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == 'X') {
                    if(board[nr][nc] == 'O'){
                        ans[nr][nc] = 'O';
                        q.push({nr, nc});
                    }
                }
            }
        }

        board = ans;
    }
};
