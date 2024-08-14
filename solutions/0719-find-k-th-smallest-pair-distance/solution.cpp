class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // Sort the array first
        sort(nums.begin(), nums.end());
        
        // Binary search for the smallest distance
        int low = 0;
        int high = nums.back() - nums.front();
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countPairs(nums, mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
    
    int countPairs(vector<int>& nums, int mid) {
        int count = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (j < nums.size() && nums[j] - nums[i] <= mid) {
                j++;
            }
            count += j - i - 1;
        }
        return count;
    }
};

