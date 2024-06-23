#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector, fast-math, O3, tree-vectorize, inline, rename-registers")
const auto speedup = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    inline long hours(const vector<int>& nums, int k) const {
        long ans = 0;
        for (const int& pile : nums) {
            ans += (pile + k - 1) / k; // Optimized division to avoid conditional
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int most = *max_element(nums.begin(), nums.end());
        int left = 1, right = most;
        int ans = most;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hours(nums, mid) <= threshold) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};




