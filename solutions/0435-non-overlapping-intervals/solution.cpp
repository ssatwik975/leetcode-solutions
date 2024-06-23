#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector, fast-math, O3, tree-vectorize, inline, rename-registers")
auto speedup = []{ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(nullptr); return(0);}();
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int ans = 0;
        int last = 0;
        for(int i = 1; i < n; ++i){
            if(intervals[i][0] < intervals[last][1]){
                ans++;
                if(intervals[i][1] < intervals[last][1]){
                    last = i;
                }
            } else {
                last = i;
            }
        }
        return ans;
    }
};
