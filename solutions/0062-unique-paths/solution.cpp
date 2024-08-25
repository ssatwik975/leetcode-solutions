class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> curr (n, 0);
        vector<int> prev (n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    up = prev[j];
                    if(j > 0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return curr[n-1];
        
    }
};
