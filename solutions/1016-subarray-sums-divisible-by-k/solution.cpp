class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> count(K);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (int& a : A) {
            prefix = (prefix + a % K + K) % K;
            res += count[prefix]++;
        }
        return res;
    }
};
