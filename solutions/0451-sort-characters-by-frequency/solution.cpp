const auto init = [](){
       std::cin.tie(nullptr);
       std::cout.tie(nullptr);
       std::ios_base::sync_with_stdio(false);
       return nullptr;
}();
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        int n = s.length();

        for(auto it:s){
            map[it]++;
        }

        sort(s.begin(), s.end(), [&](char a, char b) {
            if (map[a] == map[b]) {
                return a < b;
            }
            return map[a] > map[b];
        });

        return s;
    }
};
