class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int maxx = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxx = max(maxx, arr[i]);
            if (i == maxx) {
                ans++;
            }
        }
        return ans;
    }
};
