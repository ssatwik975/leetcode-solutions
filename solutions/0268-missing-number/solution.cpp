class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int size = nums.size();
        int total = size * (size+1) / 2;

        int sum = 0;

        for(int i=0; i < size; ++i ){
            sum += nums[i];
        }

        return total - sum;
        
    }
};
