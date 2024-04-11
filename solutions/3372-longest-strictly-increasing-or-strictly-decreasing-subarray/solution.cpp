const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    int longestMonotonicSubarray(const vector<int>& nums) {
        int ans = 1;
        int inc = 1;
        int dec = 1;
        for (int i = 1; i < nums.size(); ++i) {
            inc = nums[i - 1] < nums[i] ? inc + 1 : 1;
            dec = nums[i - 1] > nums[i] ? dec + 1 : 1;
            ans = max({ans, inc, dec});
        }
        return ans;
    }
};
