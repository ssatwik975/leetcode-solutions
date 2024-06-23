class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        if (nums[0] > nums[1]) return 0;
        if (nums[n-1] > nums[n-2]) return n-1;

        int left = 1, right = n - 2;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1]) {
                left = mid + 1; // We're on an increasing curve
            } else {
                right = mid - 1;
            }
        }

        return -1; // This should never be reached if the input guarantees a peak element
    }
};


