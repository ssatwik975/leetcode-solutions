const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> prefixsum (n, 0);
        prefixsum[0] = (possible[0] == 1) ? 1 : (-1);
        int ans = -1;

        for(int i = 1; i<n ; i++){
            prefixsum[i] = (possible[i] == 1) ? (prefixsum[i-1]+1) : (prefixsum[i-1]-1);
        }
        
        int finasco = prefixsum[n-1];
        
        for(int i = 0; i < n-1; i++){
            if(prefixsum[i]>(finasco-prefixsum[i])){
                ans = i+1;
                break;
            }
        }
        return ans;
    }
};
