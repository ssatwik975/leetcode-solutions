const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n);
        for(int i = 0; i < n; ++i){
            ans[i] = nums[i];
            ans[i+n] = nums[i];
        }
        return ans;
    }
};
