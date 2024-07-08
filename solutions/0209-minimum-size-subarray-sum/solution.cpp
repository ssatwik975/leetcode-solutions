class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int mincount = INT_MAX;
        while(right < nums.size()){
            sum += nums[right];
            while(sum >= target){
                mincount = min(mincount, ((right - left) + 1));
                sum -= nums[left];
                left++;
            }
            
            right++;
        }
        if(mincount == INT_MAX) mincount = 0;
        return mincount;
    }
};
