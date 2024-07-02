class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int ans = 0;

        unordered_map<char, int> freq;
        int maxfreq = 0;

        for (right = 0; right < n; right++) {
            freq[s[right]]++;
            maxfreq = max(maxfreq, freq[s[right]]);

            while ((right - left + 1) - maxfreq > k) {
                freq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

