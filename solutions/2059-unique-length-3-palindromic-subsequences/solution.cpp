bool sub(const string& pattern, const string& text) {
    int i, j;
    for (i = 0, j = 0; i < text.size() && j < 3; ++i) {
        if (text[i] == pattern[j])
            ++j;
    }
    return j == 3;
};

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for (char a = 'a'; a <= 'z'; ++a) {
            for (char b = 'a'; b <= 'z'; ++b) {
                string str;
                str += a;
                str += b;
                str += a;
                ans += sub(str, s);
            }
        }
        return ans;
    }
};

