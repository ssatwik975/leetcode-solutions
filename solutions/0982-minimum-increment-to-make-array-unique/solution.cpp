auto _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxval = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxval + nums.size(), 0);

        for (int num : nums) {
            freq[num]++;
        }

        int ans = 0;

        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] > 1) {
                int excess = freq[i] - 1;
                ans += excess;
                freq[i + 1] += excess;
                freq[i] = 1;
            }
        }

        return ans;
    }
};
