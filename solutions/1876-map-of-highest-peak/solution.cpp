class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size();
        int c = isWater[0].size();
        vector<vector<int>> ans(r,vector<int>(c,INT_MAX));
        queue<pair<int,int>> q;
        
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(isWater[i][j] == 1){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int dx[4] = {0,0,-1,1};
            int dy[4] = {-1,1,0,0};
            
            for(int i = 0;i<4;i++){
                int xx = x + dx[i];
                int yy = y + dy[i];
                
                if(xx>=0 && xx<r && yy>=0 && yy<c && ans[xx][yy] > 1 + ans[x][y]){
                    ans[xx][yy] = 1 + ans[x][y];
                    q.push({xx,yy});
                }
            }
        }
        return ans;
    }
};
