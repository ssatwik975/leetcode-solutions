const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        
        vector<vector<int>> result;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                if(land[i][j] == 0) continue;

                
                int ycord = j;
                while(ycord < n && land[i][ycord] == 1) {
                    ycord++;
                }

                
                int xcord = i;
                while(xcord < m && land[xcord][j] == 1) {
                    xcord++;
                }
                
            
                ycord = ycord==0 ? ycord : ycord-1;
                xcord = xcord==0 ? xcord : xcord-1;

                
                result.push_back({i, j, xcord, ycord});
                
                //island gayab
                for(int k = i; k<=xcord; k++) {
                    for(int l = j; l<=ycord; l++) {
                        land[k][l] = 0;
                    }
                }
                
            }
        }
        return result;
    }
};
