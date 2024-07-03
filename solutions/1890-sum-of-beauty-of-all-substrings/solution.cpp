class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < s.size(); j++) {
                freq[s[j] - 'a']++;
                int mx = INT_MIN;
                int mn = INT_MAX;
                for (int m : freq) {
                    if (m > 0) {
                        mx = max(m, mx);
                        mn = min(m, mn);
                    }
                }
                ans += (mx - mn);
            }
        }
        return ans;
    }
};

