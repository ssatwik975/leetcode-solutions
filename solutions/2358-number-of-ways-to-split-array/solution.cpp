class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long total = 0;
        for(int k : nums) total += k;
        long sum = 0;
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            sum+= nums[i];
            total-= nums[i];
            if(sum >= total) ans++;
        }
        return ans;
    }
};
