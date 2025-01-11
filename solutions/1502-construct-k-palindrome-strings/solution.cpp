class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        
        vector<int> freq(26);
        for (auto ch : s) freq[ch - 'a']++;
        
        int odd = 0;
        for (auto f : freq) odd += (f % 2);
        
        return odd <= k;
    }
};
