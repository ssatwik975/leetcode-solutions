int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        //same as 330
        int ans = 1;
        sort(coins.begin(), coins.end());
        for(int a : coins){
            if (a <= ans) ans += a; 
        }
        return ans;
    }
};


