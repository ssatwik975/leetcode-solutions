class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr);
        vector<int> ans;
        for(auto n : nums){
            if(n < pivot){
                ans.push_back(n);
            }
        }
        for(auto n : nums){
            if(n == pivot){
                ans.push_back(n);
            }
        }
        for(auto n : nums){
            if(n > pivot){
                ans.push_back(n);
            }
        }
        return ans;
    }
};
