const auto init = []() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    return nullptr;
}();

class Solution {
public:
    // int trap(vector<int>& height) {

    //     int n = height.size();
    //     if (n == 0)
    //         return 0;
    //     vector<int> leftsweep(n), rightsweep(n);

    //     leftsweep[0] = height[0];
    //     for (int i = 1; i < n; ++i) {
    //         leftsweep[i] = max(leftsweep[i - 1], height[i]);
    //     }

    //     rightsweep[n - 1] = height[n - 1];
    //     for (int i = n - 2; i >= 0; --i) {
    //         rightsweep[i] = max(rightsweep[i + 1], height[i]);
    //     }

    //     int ans = 0;
    //     for (int i = 0; i < n; ++i) {
    //         ans += min(leftsweep[i], rightsweep[i]) - height[i];
    //     }

    //     return ans;
    // }
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int res = 0;
        int maxLeft = 0, maxRight = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    res += maxLeft - height[left];
                }
                left++;
            } else {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    res += maxRight - height[right];
                }
                right--;
            }
        }
        return res;
    }
};

