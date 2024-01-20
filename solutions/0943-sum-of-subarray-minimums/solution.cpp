class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long sum = 0;
        int n = arr.size();

        vector<int> left(n), right(n);

        for (int i = 0; i < n; i++) {
            int count = 1;
            while (count && i - count >= 0 && arr[i] < arr[i - count]) {
                count += left[i - count];
            }
            left[i] = count;
        }

        for (int i = n - 1; i >= 0; i--) {
            int count = 1;
            while (count && i + count < n && arr[i] <= arr[i + count]) {
                count += right[i + count];
            }
            right[i] = count;
        }

        for (int i = 0; i < n; i++) {
            sum += static_cast<long long>(arr[i]) * left[i] * right[i] % MOD;
            sum %= MOD;
        }

        return static_cast<int>(sum);
    }
};
