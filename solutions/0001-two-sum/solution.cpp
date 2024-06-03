const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> storedIndices;
        for(int idx = 0; idx < nums.size(); idx++){
            int complement = target - nums[idx];
            if(storedIndices.count(complement)){        
                return {idx, storedIndices[complement]};
            }
            storedIndices[nums[idx]] = idx;            
        }
        
        return {};
    }
};
