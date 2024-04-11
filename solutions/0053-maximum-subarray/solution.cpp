const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int maxnum = nums[0];
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum = sum + nums[i];
            maxnum = max(maxnum, sum);
            if (sum < 0) sum = 0;
        }
        return maxnum;
    }
};
