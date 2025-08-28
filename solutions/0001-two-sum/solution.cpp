class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int t = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            t = target-nums[i];
            for(int j = i+1; j < n; j++){
                if(nums[j] == t){
                    return {i, j};
                }
            }
        }
        return {0,0};
    }
};
