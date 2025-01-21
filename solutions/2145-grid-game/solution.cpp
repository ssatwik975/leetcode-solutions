class Solution {
public:
    long long gridGame(vector<vector<int>>& g) {
        long long top = accumulate(begin(g[0]), end(g[0]), 0ll), bottom = 0,
                  res = LLONG_MAX;
        for (int i = 0; i < g[0].size(); ++i) {
            top -= g[0][i];
            res = min(res, max(top, bottom));
            bottom += g[1][i];
        }
        return res;
    }
};
