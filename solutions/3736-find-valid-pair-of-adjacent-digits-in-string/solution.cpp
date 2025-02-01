class Solution {
public:
    string findValidPair(string s) {
        vector<int> freq(10);
        for(char c : s) freq[c-'0']++;
        
        for(int i = 0; i < s.length()-1; i++) {
            int d1 = s[i]-'0', d2 = s[i+1]-'0';
            if(d1 != d2 && freq[d1] == d1 && freq[d2] == d2)
                return s.substr(i,2);
        }
        return "";
    }
};
