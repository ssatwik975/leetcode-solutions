const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int even = 0;
        int odd = 1;
        for(int i = 0; i < n; i++){
            if(nums[i]>0){
                ans[even] = nums[i];
                even += 2;
            }
            if (nums[i]<0){
                ans[odd] = nums[i];
                odd += 2;
            }
        }
        return ans;
    }
};
