class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = nums.size();
        vector<int> output(n, 1); 
        int left = 1;

        for (int i = 0; i < n; ++i) {
            output[i] = left;
            left *= nums[i];
        }

        int right = 1;

        for (int i = n - 1; i >= 0; --i) {
            output[i] *= right;
            right *= nums[i];
        }

        return output;
    }
};

