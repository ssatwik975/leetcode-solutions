class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    void solve(string& s, int part, vector<string>& ds, vector<vector<string>>& ans) {
        int n = s.length();
        if (part == n) {
            ans.push_back(ds);
            return;
        }
        for (int i = part; i < n; i++) {
            if (isPalindrome(s, part, i)) {
                ds.push_back(s.substr(part, i - part + 1));
                solve(s, i + 1, ds, ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(s, 0, ds, ans);
        return ans;
    }
};
