class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;

        // iterate through input vector using i pointer
        for (int i = 0; i < chars.size();) {
            const char letter = chars[i]; // current character being compressed
            int count = 0; // count of consecutive occurrences of letter

            // count consecutive occurrences of letter in input vector
            while (i < chars.size() && chars[i] == letter) {
                ++count;
                ++i;
            }

            // write letter to compressed vector
            chars[ans++] = letter;

            // if count is greater than 1, write count as string to compressed vector
            if (count > 1) {
                // convert count to string and iterate over each character in string
                for (const char c : to_string(count)) {
                    chars[ans++] = c;
                }
            }
        }

        // return length of compressed vector
        return ans;
    }
};

