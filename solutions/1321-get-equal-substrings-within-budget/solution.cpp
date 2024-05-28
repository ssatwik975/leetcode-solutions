class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = s.length();
        vector<int> diff(n);
    
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(t[i] - s[i]);
        }

        int start = 0, end = 0, sum = 0;
        while(end<n){
            sum += diff[end];
            end++;
            if (sum > maxCost){
                sum -= diff[start];
                start++;
            }
        }
        return (end - start);
    }
};
