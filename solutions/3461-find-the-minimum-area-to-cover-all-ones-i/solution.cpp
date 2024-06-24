#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector, fast-math, O3, tree-vectorize, inline, rename-registers")
auto speedup = []{ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(nullptr); return(0);}();
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int mini = m;
        int minj = n;
        int maxi = 0;
        int maxj = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==1){
                    mini = min(mini, i);
                    maxi = max(maxi, i);
                    minj = min(minj, j);
                    maxj = max(maxj, j);
                }
            }
        }

        int length = (maxi - mini) + 1;
        int breadth = (maxj - minj) + 1;

        return length*breadth;
    }
};
