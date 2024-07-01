const static auto initialize = [] {ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return nullptr;}();
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        string curr;
        for(char c: searchWord){
            curr += c;
            vector<string> suggested;
            auto ind = lower_bound(products.begin(), products.end(), curr);
            for(int i = 0; i < 3; i++){
                if(ind + i >= products.end()){
                    break;
                }
                string& s = *(ind + i);
                if (s.find(curr)) break;
                suggested.push_back(s);
            }
            ans.push_back(suggested);
        }
        return ans;
    }
};
