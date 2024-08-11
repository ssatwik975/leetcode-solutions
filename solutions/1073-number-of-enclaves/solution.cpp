class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        //first we'll solve it with a multisource bfs like in surrounded regions,
        // so we just track the boundary and choose all those 1s and then
        // mark them and everything connected to them as 0. After this its just number of islands.

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans = grid;

        queue<pair<int,int>>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                //only boundaries
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    //if it is one, push into queue
                    if(ans[i][j]==1){
                        q.push({i, j});
                    }
                }
            }
        }

        //now for the bfs

        vector<int>drow = {-1, 0, 1, 0};
        vector<int>dcol = {0, -1, 0 , 1};

        //perform multisource
        while(!q.empty()){

            int r = q.front().first;
            int c = q.front().second;

            q.pop();
            ans[r][c] = 0;
            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    if(ans[nr][nc] == 1){
                        q.push({nr, nc});
                        ans[nr][nc] = 0;
                    }
                }
            }
        }
        int count = 0;
        for(int i = 1; i < n-1; i++){
            for(int j = 1; j < m-1; j++){
                if(ans[i][j]==1){
                    count++;
                }
            }
        }
        return count;

    }   
};
