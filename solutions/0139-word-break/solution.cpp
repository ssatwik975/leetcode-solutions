class Solution {
    unordered_set<string> mp;
    int mx = 0;
    bool solve(int i, int& n, string& s, vector<int>& dp) {
        if(i==n) {
            return true;
        }
        if(dp[i]!=-1) {
            return dp[i];
        }
        for(int j=i;j<=min(n-1,mx+i-1);j++) {
            if(mp.find(s.substr(i,j-i+1))!=mp.end() && solve(j+1,n,s,dp)) {
                return dp[i] = true;
            }
        }
        return dp[i]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        mp.clear();
        for(int i=0;i<wordDict.size();i++) {
            mp.insert(wordDict[i]);
            mx = max(mx,static_cast<int>(wordDict[i].size()));
        }
        int n = s.size(); vector<int> dp(n,-1);
        return solve(0,n,s,dp);
    }
};
