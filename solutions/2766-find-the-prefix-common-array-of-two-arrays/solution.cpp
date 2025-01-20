class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> seen(51, false);
        vector<int> ans;
        int common = 0;

        for (int i = 0; i < n; ++i) {
            if (seen[A[i]]) {
                ++common;
            } else {
                seen[A[i]] = true;
            }

            if (seen[B[i]]) {
                ++common;
            } else {
                seen[B[i]] = true;
            }

            ans.push_back(common);
        }

        return ans;
    }
};
