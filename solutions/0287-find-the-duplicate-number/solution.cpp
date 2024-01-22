class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        vector<int> swag (n,0);
        int ans;
        for(int i = 0; i<n; i++){
            swag[i] = nums[i];
        }

        for(auto it: swag){
            if (swag[abs(it) - 1] < 0){
                ans = abs(it);
            } else {
                swag[abs(it)-1] *= -1;
            }

        }
        return ans;
    }
};
