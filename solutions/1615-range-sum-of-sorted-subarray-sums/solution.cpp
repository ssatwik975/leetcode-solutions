class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> pq;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                pq.push_back(sum);
            }
        }

        long ans = 0;
        long long mod = 1e9 + 7;
        sort(pq.begin(), pq.end());
        for(int i = left-1; i<right; i++){
            ans = (ans + (pq[i] % mod)) % mod;
        }
        return (int)ans;
    }
};
