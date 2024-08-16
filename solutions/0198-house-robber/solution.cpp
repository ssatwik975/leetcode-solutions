class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev = nums[0];
        int prev2 = 0;
        int curr = 0;
        for(int i = 1; i < n; i++){
            int take = nums[i];
            if(i > 1) take += prev2;
            int nontake = prev;
            curr = max(take, nontake);
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};
