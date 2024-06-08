int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size();
        for (int i = 0; i < n; i++) {
            if (citations[i] <= i) {
                return i;
            }
        }
        return n;
    }
};

