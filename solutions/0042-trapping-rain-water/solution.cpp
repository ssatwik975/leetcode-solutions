const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        if (n == 0) return 0;
        vector<int> leftsweep(n), rightsweep(n);
        
        leftsweep[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftsweep[i] = max(leftsweep[i - 1], height[i]);
        }
        
        rightsweep[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightsweep[i] = max(rightsweep[i + 1], height[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(leftsweep[i], rightsweep[i]) - height[i];
        }
        
        return ans;
    }
};
