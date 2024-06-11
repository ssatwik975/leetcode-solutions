class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt(1001, 0);
        for (int n : arr1) {
            cnt[n]++;
        }
        vector<int> ans;
        for (int n : arr2) {
            while (cnt[n] > 0) {
                ans.push_back(n);
                cnt[n]--;
            }
        }
        for (int i = 0; i < 1001; i++) {
            while (cnt[i] > 0) {
                ans.push_back(i);
                cnt[i]--;
            }
        }
        return ans;
    }
};
