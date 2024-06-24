#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector, fast-math, O3, tree-vectorize, inline, rename-registers")
auto speedup = []{ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(nullptr); return(0);}();
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flipCount(n, 0);  // Track the number of flips at each position
        int flips = 0;  // Total number of flips needed
        int ans = 0;  // Resulting number of flips

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                if (flipCount[i - k] > 0) {
                    flips--;
                }
            }

            if ((nums[i] + flips) % 2 == 0) {  // If the current bit needs to be flipped
                if (i + k > n) {
                    return -1;  // Not enough elements to flip k bits
                }

                flips++;  // Perform the flip
                flipCount[i]++;  // Mark the start of the flip
                ans++;  // Increment the flip counter
            }
        }

        return ans;
    }
};

