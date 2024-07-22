class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ones = 0;
        int k = 1;
        int left = 0;
        int right = 0;
        int maxx = 0;
        while(left < nums.size()){
            if(nums[left] == 1){
                ones++;
            }else{
                k--;
            }

            while(k < 0){
                if(nums[right] == 0){
                    k++;
                }else{
                    ones--;
                }
                right++;
            }

            maxx = max(ones, maxx);
            left++;
        }
        
        return maxx - k;
    }
};
