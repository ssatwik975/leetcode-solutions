#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector, fast-math, O3, tree-vectorize, inline, rename-registers")
auto speedup = []{ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(nullptr); return(0);}();
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flips = 0;
        vector<int> flipCount(n,0);
        int k = 3;
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(i>=k){
                if(flipCount[i-k]){
                    flips--;
                }
            }
            if((nums[i]+flips)%2 == 0){
                if(i+k>n){
                    return -1;
                }
                ans++;
                flips++;
                flipCount[i]++;
            }
        }

        return ans;
    }
};
