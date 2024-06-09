class Solution {
public:
    int maximumLengthSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int cnt[26] = {}, res = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (++cnt[s[i] - 'a'] > 2)
                while (cnt[s[i] - 'a'] > 2)
                    --cnt[s[j++] - 'a'];
            res = max(res, i - j + 1);
        }
        return res;
    }
};
