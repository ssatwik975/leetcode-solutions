class Solution {
public:
    string reverseWords(string s) {
        // Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.size();
        int start = 0;
        int end = 0;

        // Reverse each word in the reversed string
        while (start < n) {
            // Find the start of the next word
            while (start < n && s[start] == ' ')
                start++;
            end = start;
            // Find the end of the word
            while (end < n && s[end] != ' ')
                end++;
            // Reverse the word
            if (start < end) {
                reverse(s.begin() + start, s.begin() + end);
                start = end;
            }
        }

        // Clean up spaces (leading, trailing, and multiple spaces)
        int i = 0;
        int j = 0;
        while (j < n) {
            while (j < n && s[j] == ' ')
                j++;
            while (j < n && s[j] != ' ')
                s[i++] = s[j++];
            while (j < n && s[j] == ' ')
                j++;
            if (j < n)
                s[i++] = ' ';
        }
        s.resize(i);

        return s;
    }
};

