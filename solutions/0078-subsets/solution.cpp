class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>& ds, int i, vector<int>& nums){
        if(i == nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        solve(ans, ds, i+1, nums);
        ds.pop_back();
        solve(ans, ds, i+1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        solve(ans, ds, 0, nums);
        
        return ans;
    }
};
