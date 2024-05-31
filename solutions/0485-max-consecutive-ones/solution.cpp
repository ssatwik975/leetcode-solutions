class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int lt = 0, rt = 0;

        while (rt != nums.size()) {
            if (!nums[rt]) {
                ans = std::max(ans, rt - lt);
                lt = rt + 1;
            }
            rt++;
        }
        return std::max(ans, rt - lt);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
