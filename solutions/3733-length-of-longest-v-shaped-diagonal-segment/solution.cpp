class Solution {
public:
    // directions in clockwise order: ↗, ↘, ↙, ↖
    int dr[4] = { -1,  1,  1, -1 }; // row changes
    int dc[4] = {  1,  1, -1, -1 }; // col changes
    // arranged in clockwise direction so always +1 turn allowed

    int n, m;
    vector<vector<vector<vector<int>>>> dp;


    int solve(int i,int j,int direction,int turn,int search,vector<vector<int>>& grid)
    {
        int nx = i + dr[direction];
        int ny = j + dc[direction];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m || search != grid[nx][ny])
            return 0;

        if(dp[i][j][direction][turn] != -1)
        {
            return dp[i][j][direction][turn];
        }

        // Continue in same direction
        int ans = solve(nx,ny,direction,turn,2 - search,grid);
        // 2 - search toggles the value from 2 -> 0 and 0 -> 2

        // Take a clockwise turn (if turn is available)
        if(turn > 0)
        {
            // doing turn in clockwise direction so always taking the next turn according to direction
            ans = max(ans, solve(nx,ny,(direction + 1) % 4,turn - 1,2 - search,grid));
        }

        return dp[i][j][direction][turn] = ans + 1;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // dp[i][j][direction][turn] = max length from (i,j) going in "direction"
        // with "turn" (0 or 1) remaining
        dp.assign(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4,vector<int>(2,-1))));

        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int d = 0;d < 4;d++)
                    {
                        ans = max(ans, solve(i,j,d,1,2,grid) + 1);
                    }
                }
            }
        }

        return ans;
    }
};
