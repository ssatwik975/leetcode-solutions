#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> mpp;
        string num;
        string key;

        for (const string& str: strs){
            key = str;
            ranges::sort(key);
            mpp[key].emplace_back(str);
        }

        
        vector<vector<string>> ans;

        for (auto& i : mpp) {
            ans.emplace_back(i.second);
        }

        return ans;
    }
};
