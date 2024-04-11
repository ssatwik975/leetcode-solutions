const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxcount = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == 1){
                count++;
                maxcount = max(maxcount, count);
            }else{
                count = 0;
            }
        }
        return maxcount;
    }
};
