#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefixSumModMap;
        prefixSumModMap[0] = -1; // To handle the case when the sum from the start is a multiple of k
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = (sum + nums[i]) % k;
            if (prefixSumModMap.find(sum) != prefixSumModMap.end()) {
                if (i - prefixSumModMap[sum] > 1) {
                    return true;
                }
            } else {
                prefixSumModMap[sum] = i;
            }
        }

        return false;
    }
};

