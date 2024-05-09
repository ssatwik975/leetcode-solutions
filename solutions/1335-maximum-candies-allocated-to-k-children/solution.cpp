class Solution {
public:
    int maximumCandies(vector<int>& A, long long k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int left = 0, right = 1e7;
        while (left < right) {
            long sum = 0, mid = (left + right + 1) / 2;
            for (int& a : A) {
                sum += a / mid;
            }
            if (k > sum)
                right = mid - 1;
            else
                left = mid;
        }
        return left;
    }
};
