class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size();
        int n = og[0].size();
        if(og[0][0] == 1) return 0;
        vector<int> prev (n, 0);
        vector<int> curr (n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) curr[j] = 1;
                else{
                    if(og[i][j]==1) curr[j] = 0;
                    else{
                        int up = 0;
                        int left = 0;
                        if(i>0) up = prev[j];
                        if(j>0) left = curr[j-1];
                        curr[j] = up + left;
                    }
                }
            }
            prev = curr;
        }
        return curr[n-1];
    }
};
