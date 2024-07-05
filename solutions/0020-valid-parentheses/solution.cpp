class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (char c : s) {
            if (st.empty()) {
                st.push(c);
            } else if ((c == ')' && st.top() == '(') ||
                       (c == '}' && st.top() == '{') ||
                       (c == ']' && st.top() == '[')) {
                st.pop();
            } else{
                st.push(c);
            }
        }
        return st.empty();
    }
};
