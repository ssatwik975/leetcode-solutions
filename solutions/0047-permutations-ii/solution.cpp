class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};


// class Solution {
// public:
//         void solve(vector<int>& ds, unordered_map<int, int>& picked, vector<vector<int>>& ans, int n, vector<int> nums){
//         //base case
//         if(ds.size() == n){
//             ans.push_back(ds);
//             return;
//         }

//         for (auto& pair : picked) {
//             if (pair.second > 0) {
//                 // pick
//                 ds.push_back(pair.first);
//                 pair.second--;
//                 solve(ds, picked, ans, n, nums);
//                 // backtrack - notPick
//                 pair.second++;
//                 ds.pop_back();
//             }
//         }

//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ds;
//         vector<vector<int>> ans;
//         unordered_map<int, int> picked;

//         for(int num : nums){
//             picked[num]++;
//         }
//         solve(ds, picked, ans, n, nums);
//         return ans;   

//     }
// };

