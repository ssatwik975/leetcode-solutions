
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, temp = 0;
        for (int i = 0; i < bank.size(); i++) {
            int n = count(bank[i].begin(), bank[i].end(), '1');
            if (n == 0) continue;
            ans += temp * n;;
            temp = n;
        }
        return ans;
    }
};


