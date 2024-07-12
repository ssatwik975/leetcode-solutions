class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int points = 0;
        int n = s.size();

        // First pass: process the higher points pair
        if (x > y) {
            int newLength = 0;
            for (int i = 0; i < n; ++i) {
                if (newLength > 0 && s[newLength - 1] == 'a' && s[i] == 'b') {
                    points += x;
                    newLength--; // Remove the previous character
                } else {
                    s[newLength] = s[i];
                    newLength++; // Keep the character
                }
            }
            n = newLength; // Update the length of the string after first pass

            // Second pass: process the lower points pair
            newLength = 0;
            for (int i = 0; i < n; ++i) {
                if (newLength > 0 && s[newLength - 1] == 'b' && s[i] == 'a') {
                    points += y;
                    newLength--; // Remove the previous character
                } else {
                    s[newLength] = s[i];
                    newLength++; // Keep the character
                }
            }
        } else {
            int newLength = 0;
            for (int i = 0; i < n; ++i) {
                if (newLength > 0 && s[newLength - 1] == 'b' && s[i] == 'a') {
                    points += y;
                    newLength--; // Remove the previous character
                } else {
                    s[newLength] = s[i]; // Keep the character
                    newLength++;
                }
            }
            n = newLength; // Update the length of the string after first pass

            // Second pass: process the lower points pair
            newLength = 0;
            for (int i = 0; i < n; ++i) {
                if (newLength > 0 && s[newLength - 1] == 'a' && s[i] == 'b') {
                    points += x;
                    newLength--; // Remove the previous character
                } else {
                    s[newLength] = s[i];
                    newLength++; // Keep the character
                }
            }
        }

        return points;
    }
};

