class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_map<char, int> freq;
        for (const char& c : word) {
            freq[c]++;
        }

        vector<pair<char, int>> freqVec(freq.begin(), freq.end());

        sort(freqVec.begin(), freqVec.end(),
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;
             });

        unordered_map<char, int> valmap;
        int i = 0;
        int presses = 1;
        while (i < freqVec.size()) {
            for (int j = 0; j < 8 && i < freqVec.size(); j++) {
                valmap[freqVec[i].first] = presses;
                i++;
            }
            presses++;
        }

        int ans = 0;
        for (const char& c : word) {
            ans += valmap[c];
        }
        return ans;
    }
};

