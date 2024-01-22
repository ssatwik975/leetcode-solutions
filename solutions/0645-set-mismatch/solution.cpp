class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        vector<int> result(2, 0);

        for (auto it : nums) {
            if (nums[abs(it) - 1] < 0) {
                result[0] = abs(it);
            } else {
                nums[abs(it) - 1] *= -1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                result[1] = i + 1;
                break;
            }
        }

        return result;
    }
};
