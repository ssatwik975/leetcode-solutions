class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int res = 0;
        vector<int> v;
        for (auto& row : grid)
            v.insert(end(v), begin(row), end(row));
        nth_element(begin(v), begin(v) + v.size() / 2, end(v));
        for (int i = 0; i < v.size(); ++i) {
            if (abs(v[v.size() / 2] - v[i]) % x)
                return -1;
            res += abs(v[v.size() / 2] - v[i]) / x;
        }
        return res;
    }
};
