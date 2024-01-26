class Solution {
private:
    int dp[52][52][52];
    int mod = 1000000007;
    vector<pair<int, int> > moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int dfs(int i, int j, int m, int n, int maxMove)
    {
        if(i>= m || i < 0 || j>= n || j < 0)
            return 1;
        
        if(maxMove <= 0)
            return 0;
        
        int &ret = dp[i][j][maxMove];
        
        if(ret != -1)
            return ret;
        
        ret = 0;
        
        for(auto move: moves)
            ret = (ret + dfs(i+move.first, j+move.second, m, n, maxMove-1)) % mod;
        
        return ret;
    }
    
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        memset(dp, -1, sizeof dp);
        
        return dfs(startRow, startColumn, m, n, maxMove);
    }
};
