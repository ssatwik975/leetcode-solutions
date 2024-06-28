class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
        if (nums.size() < 3) {
            return false;
        }
        int n = nums.size();
        int first, second;
        first = second = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= first){
                first = nums[i];
            }else if(nums[i] <= second){
                second = nums[i];
            }else{
                return true;
            }
        }
        return false;
    }
};
