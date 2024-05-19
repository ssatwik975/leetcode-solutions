class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        long long sum = 0, cnt = 0, sacrifice = INT_MAX;
        for (long long n : nums) {
            sum += max(n ^ k, n);
            cnt += (n ^ k) > n;
            sacrifice = min(sacrifice, abs(n - (n ^ k)));
        }
        return sum - (cnt % 2 ? sacrifice : 0); 
    }
};
