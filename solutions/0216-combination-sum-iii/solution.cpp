class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &ds, int i, int k, int n, vector<int>&nums){
        if(ds.size()==k){
            if(n==0){
                ans.push_back(ds);
            }
            return;
        }
        if(i>=9){
            return;
        }
        if(n >= nums[i]){
            ds.push_back(nums[i]);
            solve(ans, ds, i+1, k, n-nums[i], nums);
            ds.pop_back();
        }
        solve(ans, ds, i+1, k, n, nums);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> ds;
        vector<vector<int>> ans;
        solve(ans, ds, 0, k, n, nums);
        return ans;
    }
};



// class Solution {
// public:
//     void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
//         if (target == 0) {
//             ans.push_back(ds);
//             return;
//         }
//         for (int i = ind; i < arr.size(); i++) {
//             if (i > ind && arr[i] == arr[i - 1])
//                 continue;
//             if (arr[i] > target)
//                 break;
//             ds.push_back(arr[i]);
//             findCombination(i + 1, target - arr[i], arr, ans, ds);
//             ds.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> ans;
//         vector<int> ds;
//         findCombination(0, target, candidates, ans, ds);
//         return ans;
//     }
// };
