class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        long long xr = 0;

        for (int num : nums) {
            xr ^= num;
        }

        long long mask = xr & (-xr);

        int xora = 0, xorb = 0;

        for (int num : nums) {
            if ((num & mask) == 0) {
                xora ^= num;
            } else {
                xorb ^= num;
            }
        }
        return {xora, xorb};
    }
};

