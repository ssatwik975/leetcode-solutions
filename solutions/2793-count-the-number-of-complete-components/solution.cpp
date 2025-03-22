class Solution {
    void dfs(int x, const vector<vector<int>> &con, vector<bool> &mark, int &a, int &b) {
        if (mark[x]) {
            return;
        }
        mark[x] = true;
        ++a;
        b += con[x].size();
        for (int y : con[x]) {
            dfs(y, con, mark, a, b);
        }
    }
    
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> con(n);
        for (const auto& e : edges) {
            con[e[0]].push_back(e[1]);
            con[e[1]].push_back(e[0]);
        }
        vector<bool> mark(n);
        int r = 0;
        for (int i = 0; i < n; ++i) {
            if (!mark[i]) {
                int x = 0, y = 0;
                dfs(i, con, mark, x, y);
                r += x * (x - 1) == y;
            }
        }
        return r;
    }
};
