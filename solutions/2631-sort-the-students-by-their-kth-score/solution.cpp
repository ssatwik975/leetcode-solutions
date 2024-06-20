class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& A, int k) {
        sort(A.begin(), A.end(), [&](auto const & a, auto const & b) {
            return a[k] > b[k];
        });
        return A;
    }
};
