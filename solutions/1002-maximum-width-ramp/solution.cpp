class Solution {
public:
    int maxWidthRamp(vector<int>& A, int res = 0) {
        vector<pair<int, int>> v;
        for (auto i = 0; i < A.size(); ++i) {
            if (v.empty() || v.back().first > A[i])
                v.push_back({A[i], i});
            else
                res = max(res, i - lower_bound(v.begin(), v.end(),
                                               make_pair(A[i], INT_MAX),
                                               greater<pair<int, int>>())
                                       ->second);
        }
        return res;
    }
};
