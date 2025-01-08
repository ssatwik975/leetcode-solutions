class Solution {
public:
    vector<int> computeLPS(const string& pat) {
        int n = pat.length();
        vector<int> lps(n, 0);
        int len = 0;

        for(int i = 1; i < n; ++i){
            while(len > 0 && pat[i] != pat[len]){
                len = lps[len -1];
            }
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
            }
        }
        return lps;
    }

    bool isPatternInText(const string& txt, const string& pat) {
        if(pat.empty()) return true;
        if(txt.length() < pat.length()) return false;

        vector<int> lps = computeLPS(pat);
        int i = 0;
        int j = 0;

        while(i < txt.length()){
            if(txt[i] == pat[j]){
                i++;
                j++;
                if(j == pat.length()){
                    return true;
                }
            }
            else{
                if(j != 0){
                    j = lps[j -1];
                }
                else{
                    i++;
                }
            }
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        sort(words.begin(), words.end(), [](const string& a, const string& b) -> bool {
            return a.length() < b.length();
        });

        for(int i = 0; i < words.size(); ++i){
            for(int j = i + 1; j < words.size(); ++j){
                if(isPatternInText(words[j], words[i])){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
