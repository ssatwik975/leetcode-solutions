class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int num1 = 0;  // Count the total number of 1's in the array
        for (int i : nums) {
            if (i == 1) num1++;
        }
        if (num1 == 0) return 0;  // If there are no 1's, no swaps are needed

        int n = nums.size();
        int count1 = 0;  // Count of 1's in the current window
        int count0 = 0;  // Count of 0's in the current window
        int ans = INT_MAX;

        // Create a sliding window of size `num1` over the circular array
        for (int i = 0; i < 2 * n; i++) {
            if (nums[i % n] == 1) {
                count1++;
            } else {
                count0++;
            }

            // Keep the window size exactly `num1`
            if (i >= num1 - 1) {
                ans = min(ans, count0);
                // Slide the window by removing the element at the start
                if (nums[(i - num1 + 1) % n] == 0) {
                    count0--;
                } else {
                    count1--;
                }
            }
        }

        return ans;
    }
};

