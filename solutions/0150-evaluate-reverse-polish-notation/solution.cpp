int speedup = [] {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return (0);
}();
class Solution {
public:
    int evalRPN(vector<string>& v) {

        stack<int> st;
        for (auto i : v) {
            if (i == "+" || i == "*" || i == "-" || i == "/") {

                int a = st.top(); // 1
                st.pop();
                int b = st.top(); // 2
                st.pop();

                if (i == "+")
                    st.push(a + b);
                if (i == "-")
                    st.push(b - a);
                if (i == "*")
                    st.push(a * b);
                if (i == "/")
                    st.push(b / a);

            } else {
                st.push(stoi(i));
            }
        }

        return st.top();
    }
};
