class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk; 
        // Traverse the string
        for (char c : s) {
            if (c == ')') {
                // Reverse the substring within parentheses
                string temp;
                while (!stk.empty() && stk.top() != '(') {
                    temp.push_back(stk.top());
                    stk.pop();
                }
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop(); // Remove the opening parenthesis '('
                }
                for (char t : temp) {
                    stk.push(t); // Push reversed characters back onto the stack
                }
            } else {
                stk.push(c); // Push the current character onto the stack
            }
        }

        // Construct the result string from the stack
        string result;
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end()); // Reverse the final result string
        return result;
    }
};

