class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>hash;
        for(int i = 0; i < n; i++){
            int look = target - nums[i];
            if(hash.find(look) != hash.end()){
                return {hash[look], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
