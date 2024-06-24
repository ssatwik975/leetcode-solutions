#pragma GCC optimize(                                                          \
    "Ofast, unroll-loops, no-stack-protector, fast-math, O3, tree-vectorize, inline, rename-registers")
auto speedup = [] {
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(nullptr);
    return (0);
}();
// same as capacity to ship packages within D days, Book allocation, Painter partition,
// Koko Eating bananas, M Bookays
class Solution {
public:
    int subsum(vector<int>& nums, int maxsum){
        int k = 1;
        int currentsum = 0;
        for(int num: nums){
            if(currentsum + num > maxsum){
                currentsum = 0;
                k++;
            }
            currentsum += num;
        }
        return k;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (subsum(nums, mid) <= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
