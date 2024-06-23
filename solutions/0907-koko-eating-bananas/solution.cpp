#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector, fast-math, O3, tree-vectorize, inline, rename-registers")
const auto speedup = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    inline long hours(const vector<int>& piles, int k) const {
        long ans = 0;
        for (const int& pile : piles) {
            ans += (pile + k - 1) / k; // Optimized division to avoid conditional
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int most = *max_element(piles.begin(), piles.end());
        int left = 1, right = most;
        int ans = most;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hours(piles, mid) <= h) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

