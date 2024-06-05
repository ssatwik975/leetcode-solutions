class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<string> res;
        
        vector<int> countmin(26,INT_MAX);
        for(const auto &s : words){
            vector<int>count(26,0);
            for(auto j : s){
                count[j-'a']++;
            }
            for (int i = 0; i<26; i++){
                countmin[i] = min(countmin[i], count[i]);
            }
        }

        for(int i = 0; i < 26; i++){
            for(int j = 0; j<countmin[i]; j++){
                res.push_back(string(1, i + 'a'));
            }
        }
        return res;
    }
};
