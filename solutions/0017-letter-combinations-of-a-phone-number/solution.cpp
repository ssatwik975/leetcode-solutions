class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> phone_map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output;
        backtrack("", digits, phone_map, output);
        return output;
    }
    void backtrack(string combination, string next_digits, vector<string> phone_map, vector<string>& output) {
        if (next_digits.empty()) {
            output.push_back(combination);
        } else {
            string letters = phone_map[next_digits[0] - '2'];
            for (char letter : letters) {
                backtrack(combination + letter, next_digits.substr(1), phone_map, output);
            }
        }
    }
};
