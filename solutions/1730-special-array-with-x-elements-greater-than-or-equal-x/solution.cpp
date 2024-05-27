class Solution {
public:
    int specialArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int x = 1; x <= n; x++) {
            // Check if there are exactly x elements >= x
            if (x <= nums[n - x] && (n - x == 0 || nums[n - x - 1] < x)) {
                return x;
            }
        }
        
        return -1;
    }
};

