class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans;
        int maxLength = 0;

        // Function to expand around the center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return s.substr(left + 1, right - left - 1);
        };

        for (int i = 0; i < n; i++) {
            // Odd length palindromes
            string oddPalindrome = expandAroundCenter(i, i);
            if (oddPalindrome.size() > maxLength) {
                maxLength = oddPalindrome.size();
                ans = oddPalindrome;
            }

            // Even length palindromes
            string evenPalindrome = expandAroundCenter(i, i + 1);
            if (evenPalindrome.size() > maxLength) {
                maxLength = evenPalindrome.size();
                ans = evenPalindrome;
            }
        }
        return ans;
    }
};

