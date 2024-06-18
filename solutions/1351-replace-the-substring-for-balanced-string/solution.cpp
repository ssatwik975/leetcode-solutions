#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        unordered_map<char, int> freq;

        // Count the frequency of each character in the string
        for (char c : s) {
            freq[c]++;
        }

        int k = n / 4; // Each character should appear exactly n/4 times for the
                       // string to be balanced

        // Find the characters that have a frequency greater than k and store
        // the excess amount
        unordered_map<char, int> excess;
        for (auto& p : freq) {
            if (p.second > k) {
                excess[p.first] = p.second - k;
            }
        }

        // If there are no excess characters, the string is already balanced
        if (excess.empty()) {
            return 0;
        }

        int minLength =
            n;        // Initialize the result with the maximum possible length
        int left = 0; // Start index of the sliding window

        // Iterate over each character as the end of the sliding window
        for (int right = 0; right < n; ++right) {
            // Decrease the frequency of the current character in the excess map
            if (excess.find(s[right]) != excess.end()) {
                excess[s[right]]--;
            }

            // Check if the current window is valid (i.e., all excess values are
            // <= 0)
            bool valid = true;
            for (auto& p : excess) {
                if (p.second > 0) {
                    valid = false;
                    break;
                }
            }

            // While the window is valid, update the minimum length and move the
            // left pointer
            while (valid) {
                minLength = min(minLength, right - left + 1);

                if (excess.find(s[left]) != excess.end()) {
                    excess[s[left]]++;
                }
                left++;

                // Check if the window is still valid after moving the left
                // pointer
                valid = true;
                for (auto& p : excess) {
                    if (p.second > 0) {
                        valid = false;
                        break;
                    }
                }
            }
        }

        return minLength; // Return the minimum length of the valid substring
    }
};

