class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        ios::sync_with_stdio(0); cin.tie(0);
        long long ops = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int mid = (size/2);
        if (k > nums[mid]) {
            for (int i = mid; i < size; ++i){ ops += max(0, k - nums[i]); }
        }
        else if (k < nums[mid]) { 
            for (int i = 0; i <= mid; ++i) { ops += max(0, nums[i] - k); }
        }
        return ops;
    }
};

