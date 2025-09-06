class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long count = 0;
        for (const vector<int> &lr : queries) {
            long long c = 0;
            long long startValue = lr[0], r = lr[1];
            for (long long highValue = 1, ops = 0; startValue <= r; highValue <<= 2, ops++) {
                if (startValue < highValue) {
                    long long endValue = min(highValue - 1, r);
                    c += (endValue - startValue + 1) * ops;
                    startValue = endValue + 1;
                }
            }
            count += (c + 1) / 2;
        }
        return count;
    }
};
