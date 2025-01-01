class Solution {
public:
    int maxScore(string s) {
        int right = 0;
        int left = 0;

        int n = s.size();
        for (char c : s) {
            if (c == '1') {
                right++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == '0') {
                left++;
            } else {
                right--;
            }
            ans = max(ans, left + right);
        }
        return ans;
    }
};
