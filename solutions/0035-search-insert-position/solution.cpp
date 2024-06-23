class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = nums.size();
        int left = 0;
        int right = ans - 1;
        int mid = 0;
        
        while(left <= right){
            mid = (left + right)/2;
            if(nums[mid]>=target){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
