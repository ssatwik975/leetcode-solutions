const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            unordered_set<char> st;
            for (int j = i; j >= 1; j--) {
                if (st.find(s[j - 1]) != st.end()) {
                    break;
                }
                st.insert(s[j - 1]);
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
        return dp[n];
    }
};
