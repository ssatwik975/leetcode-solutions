class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int start = 0; int end = 0; int ans = 0;
        int counter = 0;
        while(end<nums.size()){
            if(nums[end]%2){
                k--;
                counter = 0;
            }
            while(k == 0){
                counter++;
                k = k + (nums[start]%2);
                start++;
            }
            ans += counter;
            end++;
        }
        return ans;
    }
};
