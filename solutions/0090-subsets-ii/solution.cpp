class Solution {
public:
    // void solve(set<vector<int>>&ans, vector<int>& ds, int i, vector<int>& nums){
    //     if(i == nums.size()){
    //         ans.insert(ds);
    //         return;
    //     }
    //     ds.push_back(nums[i]);
    //     solve(ans, ds, i+1, nums);
    //     ds.pop_back();
    //     solve(ans, ds, i+1, nums);
    // }
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     vector<int> ds;
    //     set<vector<int>> ans;
    //     solve(ans, ds, 0, nums);
    //     vector<vector<int>> realans;
    //     for(auto n : ans){
    //         realans.push_back(n);
    //     }
    //     return realans;
    // }

    void solve(int ind, vector<int>& nums, vector<int>&ds, vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i = ind; i < nums.size(); i++){
            if(i != ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(i+1, nums, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums){
        sort(nums.begin(), nums.end());
        vector<int>ds;
        vector<vector<int>>ans;
        solve(0, nums, ds, ans);
        return ans;
    }
};
