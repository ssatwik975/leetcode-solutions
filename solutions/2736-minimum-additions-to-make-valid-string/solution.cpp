class Solution {
 public:
    int addMinimum(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans = 0, i = 0;
        while(i < word.size()){
            (word[i] == 'a') ? i++ : ans++;         
            (word[i] == 'b') ? i++ : ans++;
            (word[i] == 'c') ? i++ : ans++;
        }
        return ans;
    }
};
