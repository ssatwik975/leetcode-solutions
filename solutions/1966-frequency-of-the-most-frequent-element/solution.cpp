#pragma GCC target("avx,mmx,sse2,sse3,sse4")
auto _ = []() noexcept {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        // std::sort(nums.begin(), nums.end());
        sort(begin(nums), end(nums));
        long long sum = 0; // To track the sum of the elements in the current window
        int maxFreq = 0; // To store the maximum frequency
        int l = 0;       // Left boundary of the window

        for (int r = 0; r < nums.size(); ++r) {
            sum += nums[r]; // Add the current element to the sum
            // While the current window is not valid (i.e., we need more than k
            // operations to equalize the window)
            while (static_cast<long long>(nums[r]) * (r - l + 1) - sum > k) {
                sum -= nums[l]; // Subtract the leftmost element
                ++l;            // Move the left boundary to the right
            }
            // Update the maximum frequency
            maxFreq = max(maxFreq, r - l + 1);
        }
        return maxFreq;
    }
};
