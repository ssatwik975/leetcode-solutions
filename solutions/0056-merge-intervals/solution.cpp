#pragma GCC optimize("Ofast, unroll-loops, no-stack-protector, fast-math, O3, tree-vectorize, inline, rename-registers")
auto speedup = []{ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(nullptr); return(0);}();
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());

        vector<vector<int>>ans;
        ans.emplace_back(intervals[0]);

        for(int i=1;i<n;i++){

            if(ans.back()[1]>=intervals[i][0]){
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else{
                ans.emplace_back(intervals[i]);
            }
        }
        return ans;
    }
};
