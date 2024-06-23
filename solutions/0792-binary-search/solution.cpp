class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
