#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, vector<int>& ds, int sum, vector<vector<int>>& ans) {

        if (i == candidates.size()) {
            if (sum == target) {
                ans.push_back(ds);
            }
            return;
        }


        if (sum + candidates[i] <= target) {
            sum += candidates[i];
            ds.push_back(candidates[i]);
            solve(candidates, target, i, ds, sum, ans); 
            ds.pop_back();
            sum -= candidates[i];
        }

        solve(candidates, target, i + 1, ds, sum, ans);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int sum = 0;
        int i = 0;
        solve(candidates, target, i, ds, sum, ans); 
        return ans;
    }
};

