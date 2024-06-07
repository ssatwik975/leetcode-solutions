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
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> S(dictionary.begin(), dictionary.end());
        string ans;
        string word;
        int found = 0;
        for(char c: sentence)
        {
            if(c != ' ')
            {
                word += c;
                if(!found && S.count(word))
                {
                    found = 1;
                    ans += word;
                }
            }
            else
            {
                if(!found) ans += word;
                
                ans += " ";
                
                found = 0;
                word = "";
            }
        }
        if(!found) ans += word;
        return ans;
    }
};
