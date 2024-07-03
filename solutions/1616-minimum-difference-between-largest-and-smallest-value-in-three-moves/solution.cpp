class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 3) return 0;
        sort(nums.begin(), nums.end());
        
        int ans = INT_MAX;
        
        ans = min(ans, abs(nums[3] - nums[n - 1]));
        
        // CASE 2: when change two from beg and one from last
        ans = min(ans, abs(nums[2] - nums[n - 2]));
        
        // CASE 3: when change only from beg and two from last
        ans = min(ans, abs(nums[1] - nums[n - 3]));
        
        // CASE 4: when change all the values from last
        ans = min(ans, abs(nums[0] - nums[n - 4]));
        
        return ans;
    }
};
